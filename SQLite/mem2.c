#ifdef __GLIBC__
  extern int backtrace(void**,int); //函数用于获取当前线程的调用堆栈，获取的信息将会被存在指针数组中，函数返回值是实际获取的指针的个数。
  extern void backtrace_symbols_fd(void*const*,int,int);  //从backtrace函数获取的信息转化为一个字符串数组，函数返回将结果写入文件描述符为fd的文件中，每个函数对应一行。
#else
# define backtrace(A,B) 1
# define backtrace_symbols_fd(A,B,C)
#endif
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef SQLITE_INT64_TYPE
  typedef SQLITE_INT64_TYPE sqlite_int64;
  typedef unsigned SQLITE_INT64_TYPE sqlite_uint64;
#elif defined(_MSC_VER) || defined(__BORLANDC__)
  typedef __int64 sqlite_int64;
  typedef unsigned __int64 sqlite_uint64;
#else
  typedef long long int sqlite_int64;
  typedef unsigned long long int sqlite_uint64;
#endif
typedef sqlite_int64 sqlite3_int64;
typedef sqlite_uint64 sqlite3_uint64;
typedef sqlite3_int64 i64;
typedef unsigned char u8; 
#define MEMTYPE_HEAP       0x01
#define SQLITE_PTR_TO_INT(X)  ((int)(((char*)X)-(char*)0))
#define ROUND8(x)     (((x)+7)&~7)

#define SQLITE_OK           0   /* Successful result */
  /* beginning-of-error-codes */
#define SQLITE_ERROR        1   /* SQL error or missing database */
#define SQLITE_INTERNAL     2   /* Internal logic error in SQLite */
#define SQLITE_PERM         3   /* Access permission denied */
#define SQLITE_ABORT        4   /* Callback routine requested an abort */
#define SQLITE_BUSY         5   /* The database file is locked */
#define SQLITE_LOCKED       6   /* A table in the database is locked */
#define SQLITE_NOMEM        7   /* A malloc() failed */
#define SQLITE_READONLY     8   /* Attempt to write a readonly database */
#define SQLITE_INTERRUPT    9   /* Operation terminated by sqlite3_interrupt()*/
#define SQLITE_IOERR       10   /* Some kind of disk I/O error occurred */
#define SQLITE_CORRUPT     11   /* The database disk image is malformed */
#define SQLITE_NOTFOUND    12   /* Unknown opcode in sqlite3_file_control() */
#define SQLITE_FULL        13   /* Insertion failed because database is full */
#define SQLITE_CANTOPEN    14   /* Unable to open the database file */
#define SQLITE_PROTOCOL    15   /* Database lock protocol error */
#define SQLITE_EMPTY       16   /* Database is empty */
#define SQLITE_SCHEMA      17   /* The database schema changed */
#define SQLITE_TOOBIG      18   /* String or BLOB exceeds size limit */
#define SQLITE_CONSTRAINT  19   /* Abort due to constraint violation */
#define SQLITE_MISMATCH    20   /* Data type mismatch */
#define SQLITE_MISUSE      21   /* Library used incorrectly */
#define SQLITE_NOLFS       22   /* Uses OS features not supported on host */
#define SQLITE_AUTH        23   /* Authorization denied */
#define SQLITE_FORMAT      24   /* Auxiliary database format error */
#define SQLITE_RANGE       25   /* 2nd parameter to sqlite3_bind out of range */
#define SQLITE_NOTADB      26   /* File opened that is not a database file */
#define SQLITE_ROW         100  /* sqlite3_step() has another row ready */
#define SQLITE_DONE        101  /* sqlite3_step() has finished executing */

//内存分配结构
struct MemBlockHdr {
  i64 iSize;                          /* Size of this allocation  分配的大小*/
  struct MemBlockHdr *pNext, *pPrev;  /* Linked list of all unfreed memory  所有未释放内存链表*/
  char nBacktrace;                    /* Number of backtraces on this alloc  这个分配的跟踪指针数*/
  char nBacktraceSlots;               /* Available backtrace slots     可跟踪指针槽 */
  u8 nTitle;                          /* Bytes of title; includes '\0'    标题字节,包括 '\0'*/
  u8 eType;                           /* Allocation type code    分配类型代码*/
  int iForeGuard;                     /* Guard word for sanity     保护字*/
} MemBlockHdr;

//保护字段
#define FOREGUARD 0x80F5E153
#define REARGUARD 0xE4676B53

#define NCSIZE  1000

static struct {
  
  //sqlite3_mutex *mutex;
  int mutex;

  struct MemBlockHdr *pFirst;
  struct MemBlockHdr *pLast;
  
  int nBacktrace;
  void (*xBacktrace)(int, int, void **);

  int nTitle;        /* Bytes of zTitle to save.  Includes '\0' and padding  保存zTitle的字节,包括'\ 0'和填充*/
  char zTitle[100];  /* The title text 标题文本 */

  int disallow; /* Do not allow memory allocation  不让内存分配*/

  int nAlloc[NCSIZE];      /* Total number of allocations 分配总数*/
  int nCurrent[NCSIZE];    /* Current number of allocations 当前分配数量*/
  int mxCurrent[NCSIZE];   /* Highwater mark for nCurrent 分配数量的高水平线*/

} mem;

int sqlite3Strlen30(const char *z){
  const char *z2 = z;
  if( z==0 ) return 0;
    while( *z2 ){ z2++; }
  return 0x3fffffff & (int)(z2 - z);
}

//调整内存使用情况
static void adjustStats(int iSize, int increment){
  int i = ROUND8(iSize)/8;
  if( i>NCSIZE-1 ){
    i = NCSIZE - 1;
  }
  if( increment>0 ){
    mem.nAlloc[i]++;
    mem.nCurrent[i]++;
    if( mem.nCurrent[i]>mem.mxCurrent[i] ){
      mem.mxCurrent[i] = mem.nCurrent[i];
    }
  }else{
    mem.nCurrent[i]--;
    assert( mem.nCurrent[i]>=0 );
  }
}

//函数设置哨兵对内存破坏进行检查
static struct MemBlockHdr *sqlite3MemsysGetHeader(void *pAllocation){
  struct MemBlockHdr *p;
  int *pInt;
  u8 *pU8;
  int nReserve;

  p = (struct MemBlockHdr*)pAllocation;
  p--;
  assert( p->iForeGuard==(int)FOREGUARD );
  nReserve = ROUND8(p->iSize);
  pInt = (int*)pAllocation;
  pU8 = (u8*)pAllocation;
  assert( pInt[nReserve/sizeof(int)]==(int)REARGUARD );
  /* This checks any of the "extra" bytes allocated due
  ** to rounding up to an 8 byte boundary to ensure 
  ** they haven't been overwritten.
  **
  ** 这检查任何"额外的"分配的字节数四舍五入到8字节边界，以确保他们没有被覆盖。
  */
  while( nReserve-- > p->iSize ) assert( pU8[nReserve]==0x65 );
  return p;
}

static int sqlite3MemSize(void *p){
  struct MemBlockHdr *pHdr;
  if( !p ){
    return 0;
  }
  pHdr = sqlite3MemsysGetHeader(p);
  return pHdr->iSize;
}

static int sqlite3MemInit(void *NotUsed){
  //UNUSED_PARAMETER(NotUsed);
  assert( (sizeof(struct MemBlockHdr)&7) == 0 );
  //if( !sqlite3GlobalConfig.bMemstat ){
    /* If memory status is enabled, then the malloc.c wrapper will already
    ** hold the STATIC_MEM mutex when the routines here are invoked. */
    /*如果内存状态为已启动, 那么例程将在malloc.c封装于已持有的ATATIC_MEM互斥体里时调用。*/
    //mem.mutex = sqlite3MutexAlloc(SQLITE_MUTEX_STATIC_MEM);
  //}
  return SQLITE_OK;
}

static void sqlite3MemShutdown(void *NotUsed){
  //UNUSED_PARAMETER(NotUsed);
  mem.mutex = 0;
}

static int sqlite3MemRoundup(int n){
  return ROUND8(n);
}

//函数填充伪随机字节的缓冲区，预留一个内存分配到不可预测值并清除释放不可预测值的内容。
static void randomFill(char *pBuf, int nByte){
  unsigned int x, y, r;
  x = SQLITE_PTR_TO_INT(pBuf);
  y = nByte | 1;
  while( nByte >= 4 ){
    x = (x>>1) ^ (-(x&1) & 0xd0000001);
    y = y*1103515245 + 12345;
    r = x ^ y;
    *(int*)pBuf = r;
    pBuf += 4;
    nByte -= 4;
  }
  while( nByte-- > 0 ){
    x = (x>>1) ^ (-(x&1) & 0xd0000001);
    y = y*1103515245 + 12345;
    r = x ^ y;
    *(pBuf++) = r & 0xff;
  }
}

//分配内存
static void *sqlite3MemMalloc(int nByte){
  struct MemBlockHdr *pHdr;
  void **pBt;
  char *z;
  int *pInt;
  void *p = 0;
  int totalSize;
  int nReserve;
  //sqlite3_mutex_enter(mem.mutex);
  assert( mem.disallow==0 );
  nReserve = ROUND8(nByte);
  totalSize = nReserve + sizeof(*pHdr) + sizeof(int) +
               mem.nBacktrace*sizeof(void*) + mem.nTitle;
  p = malloc(totalSize);
  if( p ){
    z = p;
    pBt = (void**)&z[mem.nTitle];
    pHdr = (struct MemBlockHdr*)&pBt[mem.nBacktrace];
    pHdr->pNext = 0;
    pHdr->pPrev = mem.pLast;
    if( mem.pLast ){
      mem.pLast->pNext = pHdr;
    }else{
      mem.pFirst = pHdr;
    }
    mem.pLast = pHdr;
    pHdr->iForeGuard = FOREGUARD;
    pHdr->eType = MEMTYPE_HEAP;
    pHdr->nBacktraceSlots = mem.nBacktrace;
    pHdr->nTitle = mem.nTitle;
    if( mem.nBacktrace ){
      /*如果backtrace深度为0.那么就不用执行*/
      void *aAddr[40];
      pHdr->nBacktrace = backtrace(aAddr, mem.nBacktrace+1)-1;
      memcpy(pBt, &aAddr[1], pHdr->nBacktrace*sizeof(void*));
      assert(pBt[0]);
      if( mem.xBacktrace ){
      /*如果有回调函数，那么执行回调函数*/
        mem.xBacktrace(nByte, pHdr->nBacktrace-1, &aAddr[1]);
      }
    }else{
      pHdr->nBacktrace = 0;
    }
    if( mem.nTitle ){
      memcpy(z, mem.zTitle, mem.nTitle);
    }
    pHdr->iSize = nByte;
    adjustStats(nByte, +1);
    pInt = (int*)&pHdr[1];
    pInt[nReserve/sizeof(int)] = REARGUARD;
    randomFill((char*)pInt, nByte);
    memset(((char*)pInt)+nByte, 0x65, nReserve-nByte);
    p = (void*)pInt;
  }
  //sqlite3_mutex_leave(mem.mutex);
  return p; 
}

//释放内存
static void sqlite3MemFree(void *pPrior){
  struct MemBlockHdr *pHdr;
  void **pBt;
  char *z;
  //assert( sqlite3GlobalConfig.bMemstat || sqlite3GlobalConfig.bCoreMutex==0 || mem.mutex!=0 );
  pHdr = sqlite3MemsysGetHeader(pPrior);
  pBt = (void**)pHdr;
  pBt -= pHdr->nBacktraceSlots;
  //sqlite3_mutex_enter(mem.mutex);
  if( pHdr->pPrev ){
    assert( pHdr->pPrev->pNext==pHdr );
    pHdr->pPrev->pNext = pHdr->pNext;
  }else{
    assert( mem.pFirst==pHdr );
    mem.pFirst = pHdr->pNext;
  }
  if( pHdr->pNext ){
    assert( pHdr->pNext->pPrev==pHdr );
    pHdr->pNext->pPrev = pHdr->pPrev;
  }else{
    assert( mem.pLast==pHdr );
    mem.pLast = pHdr->pPrev;
  }
  z = (char*)pBt;
  z -= pHdr->nTitle;
  adjustStats(pHdr->iSize, -1);
  randomFill(z, sizeof(void*)*pHdr->nBacktraceSlots + sizeof(*pHdr) +
                pHdr->iSize + sizeof(int) + pHdr->nTitle);
  free(z);
  //sqlite3_mutex_leave(mem.mutex);  
}

//调整内存
static void *sqlite3MemRealloc(void *pPrior, int nByte){
  struct MemBlockHdr *pOldHdr;
  void *pNew;
  assert( mem.disallow==0 );
  assert( (nByte & 7)==0 );     /* EV: R-46199-30249 */
  pOldHdr = sqlite3MemsysGetHeader(pPrior);
  pNew = sqlite3MemMalloc(nByte);
  if( pNew ){
    memcpy(pNew, pPrior, nByte<pOldHdr->iSize ? nByte : pOldHdr->iSize);
    if( nByte>pOldHdr->iSize ){
      randomFill(&((char*)pNew)[pOldHdr->iSize], nByte - pOldHdr->iSize);
    }
    sqlite3MemFree(pPrior);
  }
  return pNew;
}

/*
void sqlite3MemSetDefault(void){
  static const sqlite3_mem_methods defaultMethods = {
     sqlite3MemMalloc,
     sqlite3MemFree,
     sqlite3MemRealloc,
     sqlite3MemSize,
     sqlite3MemRoundup,
     sqlite3MemInit,
     sqlite3MemShutdown,
     0
  };
  sqlite3_config(SQLITE_CONFIG_MALLOC, &defaultMethods);
}
*/

//设置内存分配的类型
void sqlite3MemdebugSetType(void *p, u8 eType){
  //if( p && sqlite3GlobalConfig.m.xMalloc==sqlite3MemMalloc ){
  if( p){
    struct MemBlockHdr *pHdr;
    pHdr = sqlite3MemsysGetHeader(p);
    assert( pHdr->iForeGuard==FOREGUARD );
    pHdr->eType = eType;
  }
}

//函数使用assert（）语句验证内存分配的类型
int sqlite3MemdebugHasType(void *p, u8 eType){
  int rc = 1;
  //if( p && sqlite3GlobalConfig.m.xMalloc==sqlite3MemMalloc ){
  if( p ){
    struct MemBlockHdr *pHdr;
    pHdr = sqlite3MemsysGetHeader(p);
    assert( pHdr->iForeGuard==FOREGUARD );         /* Allocation is valid 分配是有效的*/
    if( (pHdr->eType&eType)==0 ){
      rc = 0;
    }
  }
  return rc;
}

//验证内存分配的类型
int sqlite3MemdebugNoType(void *p, u8 eType){
  int rc = 1;
  //if( p && sqlite3GlobalConfig.m.xMalloc==sqlite3MemMalloc ){
  if( p ){
    struct MemBlockHdr *pHdr;
    pHdr = sqlite3MemsysGetHeader(p);
    assert( pHdr->iForeGuard==FOREGUARD );         /* Allocation is valid 分配是有效的*/
    if( (pHdr->eType&eType)!=0 ){
      rc = 0;
    }
  }
  return rc;
}

//函数设置每个内存分配回溯跟踪级别数
void sqlite3MemdebugBacktrace(int depth){
  if( depth<0 ){ depth = 0; }
  if( depth>20 ){ depth = 20; }
  depth = (depth+1)&0xfe;
  mem.nBacktrace = depth;
}

//函数内存分配的回调函数
void sqlite3MemdebugBacktraceCallback(void (*xBacktrace)(int, int, void **)){
  mem.xBacktrace = xBacktrace;
}

//函数设置标题字符串进行后续的分配
void sqlite3MemdebugSettitle(const char *zTitle){
  unsigned int n = sqlite3Strlen30(zTitle) + 1;
  //sqlite3_mutex_enter(mem.mutex);
  if( n>=sizeof(mem.zTitle) ) n = sizeof(mem.zTitle)-1;
  memcpy(mem.zTitle, zTitle, n);
  mem.zTitle[n] = 0;
  mem.nTitle = ROUND8(n);
  //sqlite3_mutex_leave(mem.mutex);
}

//函数同步
void sqlite3MemdebugSync(){
  struct MemBlockHdr *pHdr;
  for(pHdr=mem.pFirst; pHdr; pHdr=pHdr->pNext){
    void **pBt = (void**)pHdr;
    pBt -= pHdr->nBacktraceSlots;
    mem.xBacktrace(pHdr->iSize, pHdr->nBacktrace-1, &pBt[1]);
  }
}

//函数打印调用栈
void sqlite3MemdebugDump(const char *zFilename){
  FILE *out;
  struct MemBlockHdr *pHdr;
  void **pBt;
  int i;
  out = fopen(zFilename, "w");
  if( out==0 ){
    fprintf(stderr, "** Unable to output memory debug output log: %s **\n",
                    zFilename);
    return;
  }
  for(pHdr=mem.pFirst; pHdr; pHdr=pHdr->pNext){
    char *z = (char*)pHdr;
    z -= pHdr->nBacktraceSlots*sizeof(void*) + pHdr->nTitle;
    fprintf(out, "**** %lld bytes at %p from %s ****\n", 
            pHdr->iSize, &pHdr[1], pHdr->nTitle ? z : "???");
    if( pHdr->nBacktrace ){
      fflush(out);
      pBt = (void**)pHdr;
      pBt -= pHdr->nBacktraceSlots;
      backtrace_symbols_fd(pBt, pHdr->nBacktrace, fileno(out));
      fprintf(out, "\n");
    }
  }
  fprintf(out, "COUNTS:\n");
  for(i=0; i<NCSIZE-1; i++){
    if( mem.nAlloc[i] ){
      fprintf(out, "   %5d: %10d %10d %10d\n", 
            i*8, mem.nAlloc[i], mem.nCurrent[i], mem.mxCurrent[i]);
    }
  }
  if( mem.nAlloc[NCSIZE-1] ){
    fprintf(out, "   %5d: %10d %10d %10d\n",
             NCSIZE*8-8, mem.nAlloc[NCSIZE-1],
             mem.nCurrent[NCSIZE-1], mem.mxCurrent[NCSIZE-1]);
  }
  fclose(out);
}

//函数返回sqlite3MemdebugMalloc()被调用的次数
int sqlite3MemdebugMallocCount(){
  int i;
  int nTotal = 0;
  for(i=0; i<NCSIZE; i++){
    nTotal += mem.nAlloc[i];
  }
  return nTotal;
}

int main(){
	void *p = NULL;
	void *p1 = NULL;
	int memSize;
	printf("mem2 test\n");

	printf("分配内存...\n");
	p = sqlite3MemMalloc(1024);
	memSize = sqlite3MemSize(p);
	printf("分配大小为:%d\n",memSize);

	printf("调整内存大小...\n");
	p1 = sqlite3MemRealloc(p,2048);
	memSize = sqlite3MemSize(p1);
	printf("调整后的内存大小为:%d\n",memSize);

	printf("释放内存...\n");
	sqlite3MemFree(p1);

	return 0;
}
