//#include "sqliteInt.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <sys/sysctl.h>
//static malloc_zone_t* _sqliteZone_;

#define SQLITE_MALLOC(x)    malloc(x)
#define SQLITE_FREE(x)      free(x)
#define SQLITE_REALLOC(x,y) realloc((x),(y))

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

typedef unsigned int u64;  //改变数据类型 
typedef u64 sqlite3_int64;

#ifdef HAVE_MALLOC_USABLE_SIZE
# ifndef SQLITE_MALLOCSIZE
#  define SQLITE_MALLOCSIZE(x) malloc_usable_size(x)
# endif
#else
# undef SQLITE_MALLOCSIZE
#endif


//在内存的动态分配存储区中分配一块长度为nByte字节的连续区域，参数nByte为需要内存空间的长度，返回该区域的首地址。
static void *sqlite3MemMalloc(int nByte){
#ifdef SQLITE_MALLOCSIZE
  void *p = SQLITE_MALLOC( nByte );
  if( p==0 ){
    //testcase( sqlite3GlobalConfig.xLog!=0 );
    //sqlite3_log(SQLITE_NOMEM, "failed to allocate %u bytes of memory", nByte);
	printf("分配失败\n");
  }
  return p;
#else
  sqlite3_int64 *p;
  assert( nByte>0 );
  //nByte = ROUND8(nByte);
  p = SQLITE_MALLOC( nByte+8 );
  if( p ){
    p[0] = nByte;
    p++;
  }else{
    //testcase( sqlite3GlobalConfig.xLog!=0 );
    //sqlite3_log(SQLITE_NOMEM, "failed to allocate %u bytes of memory", nByte);
	printf("分配失败\n");
  }
  return (void *)p;
#endif
}

//释放pPrior指向的存储空间，被释放的空间通常被送入可用存储区域，以后可在调用malloc、realloc函数来再分配。
static void sqlite3MemFree(void *pPrior){
#ifdef SQLITE_MALLOCSIZE
  SQLITE_FREE(pPrior);
#else
  sqlite3_int64 *p = (sqlite3_int64*)pPrior;
  assert( pPrior!=0 );
  p--;
  SQLITE_FREE(p);
#endif
}

//函数返回已分配内存的大小，也能够跟踪未归还内存的字节数，它能确定当一个分配被释放时有多少字节从未归还内存中移除。
static int sqlite3MemSize(void *pPrior){
#ifdef SQLITE_MALLOCSIZE
  return pPrior ? (int)SQLITE_MALLOCSIZE(pPrior) : 0;
#else
  sqlite3_int64 *p;
  if( pPrior==0 ) return 0;
  p = (sqlite3_int64*)pPrior;
  p--;
  return (int)p[0];
#endif
}

//给一个已经分配了地址的指针重新分配空间，参数pPrior为原有空间地址，nByte是重新申请的地址长度。
static void *sqlite3MemRealloc(void *pPrior, int nByte){
#ifdef SQLITE_MALLOCSIZE
  void *p = SQLITE_REALLOC(pPrior, nByte);
  if( p==0 ){
    //testcase( sqlite3GlobalConfig.xLog!=0 );
	printf("分配失败\n");
	/*
    sqlite3_log(SQLITE_NOMEM,
      "failed memory resize %u to %u bytes",
      SQLITE_MALLOCSIZE(pPrior), nByte);
	  */
  }
  return p;
#else
  sqlite3_int64 *p = (sqlite3_int64*)pPrior;
  assert( pPrior!=0 && nByte>0 );
  //assert( nByte==ROUND8(nByte) ); /* EV: R-46199-30249 */
  p--;
  p = SQLITE_REALLOC(p, nByte+8 );
  if( p ){
    p[0] = nByte;
    p++;
  }else{
    //testcase( sqlite3GlobalConfig.xLog!=0 );
	printf("分配失败\n");
	/*
    sqlite3_log(SQLITE_NOMEM,
      "failed memory resize %u to %u bytes",
      sqlite3MemSize(pPrior), nByte);
	  */
  }
  return (void*)p;
#endif
}

//函数返回下一个有效内存分配的大小。
static int sqlite3MemRoundup(int n){
  //return ROUND8(n);
  printf("向上舍入\n");
}

//函数初始化
static int sqlite3MemInit(void *NotUsed){
#if defined(__APPLE__) && !defined(SQLITE_WITHOUT_ZONEMALLOC)
  int cpuCount;
  size_t len;
  if( _sqliteZone_ ){
    return SQLITE_OK;
  }
  len = sizeof(cpuCount);
  /* One usually wants to use hw.acctivecpu for MT decisions, but not here */
  /*通常希望使用hw.acctivecpu为MT的决定，但是不是在这里*/
  sysctlbyname("hw.ncpu", &cpuCount, &len, NULL, 0);
  if( cpuCount>1 ){
    /* defer MT decisions to system malloc */
    /*推迟MT决策系统的malloc*/
    _sqliteZone_ = malloc_default_zone();
  }else{
    /* only 1 core, use our own zone to contention over global locks, 
    ** e.g. we have our own dedicated locks */
    /*仅有一个核心，使用我们的区域在争用全局锁，例如，我们只有自己的专用锁*/
    bool success;
    malloc_zone_t* newzone = malloc_create_zone(4096, 0);
    malloc_set_zone_name(newzone, "Sqlite_Heap");
    do{
      success = OSAtomicCompareAndSwapPtrBarrier(NULL, newzone, 
                                 (void * volatile *)&_sqliteZone_);
    }while(!_sqliteZone_);
    if( !success ){
      /* somebody registered a zone first */
      /*有人已先注册区域*/
      malloc_destroy_zone(newzone);
    }
  }
#endif
  //UNUSED_PARAMETER(NotUsed);
  return SQLITE_OK;
}

//取消函数的初始化
static void sqlite3MemShutdown(void *NotUsed){
  //UNUSED_PARAMETER(NotUsed);
  return;
}

//函数填充底层的内存分配函数指针
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
int main(){
	void *p=NULL;
	void *p1=NULL;
	int memSize;
	printf("mem1 test\n");

	printf("分配内存...\n");
	p=sqlite3MemMalloc(1024);
	memSize = sqlite3MemSize(p);
	printf("分配内存的大小为:%d\n",memSize);

	printf("调整内存...\n");
	p1 = sqlite3MemRealloc(p,2048);
	memSize = sqlite3MemSize(p1);
	printf("调整后的内存大小为:%d\n",memSize);

	printf("释放内存...\n");
	sqlite3MemFree(p1);

	return 0;
	/*
	 * 每次分配多占用8字节
	 *
	 */ 
}
