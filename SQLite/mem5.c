#include "tmp.h"

//#ifdef SQLITE_ENABLE_MEMSYS5

typedef struct Mem5Link Mem5Link;
struct Mem5Link {
  int next;       /* Index of next free chunk  下一个空闲块的索引*/
  int prev;       /* Index of previous free chunk  上一个空闲块的索引*/
};

#define LOGMAX 30             /*宏定义LOGMAX为30*/

#define CTRL_LOGSIZE  0x1f    /* Log2 Size of this block 宏定义CTRL_LOGSIZE块的大小，为16进制的1f，即十进制的31*/
#define CTRL_FREE     0x20    /* True if not checked out 宏定义，十进制的32*/

//static SQLITE_WSD struct Mem5Global {
struct Mem5Global {
  //可用内存分配
  int szAtom;      /* Smallest possible allocation in bytes  以字节为单位的最小可能分配*/
  int nBlock;      /* Number of szAtom sized blocks in zPool  在zPool存储池中大小为szAtom的块数目 */
  u8 *zPool;       /* Memory available to be allocated  可用来分配的内存，zPool是无符号字符类型的指针*/
  
  //互斥访问内存子系统
  //sqlite3_mutex *mutex;  
  int *mutex;  

  //性能统计信息
  u64 nAlloc;         /* Total number of calls to malloc  调用malloc总数*/
  u64 totalAlloc;     /* Total of all malloc calls - includes internal frag  所有Mallocde调用总合— 包括内部碎片*/
  u64 totalExcess;    /* Total internal fragmentation 总内部碎片*/
  u32 currentOut;     /* Current checkout, including internal fragmentation  当前检出，包括内部碎片*/
  u32 currentCount;   /* Current number of distinct checkouts  当前不同的检出数*/
  u32 maxOut;         /* Maximum instantaneous currentOut  currentOut瞬时最大值*/
  u32 maxCount;       /* Maximum instantaneous currentCount  currentCount 瞬时最大值*/
  u32 maxRequest;     /* Largest allocation (exclusive of internal frag)  最大分配（不包括内部碎片）*/

  int aiFreelist[LOGMAX+1];

  u8 *aCtrl; //用于追踪检出块和每块的大小，每个块一个字节

} mem5;
struct Mem5Global mem5;

//#define mem5 GLOBAL(struct Mem5Global, mem5)

#define MEM5LINK(idx) ((Mem5Link *)(&mem5.zPool[(idx)*mem5.szAtom]))

//从双向循环链表中删除第i项chunk,该chunk位于mem5.aiFreelist[iLogsize]处
static void memsys5Unlink(int i, int iLogsize){
  int next, prev;
  assert( i>=0 && i<mem5.nBlock );
  assert( iLogsize>=0 && iLogsize<=LOGMAX );
  assert( (mem5.aCtrl[i] & CTRL_LOGSIZE)==iLogsize );
  next = MEM5LINK(i)->next;
  prev = MEM5LINK(i)->prev;              
  if( prev<0 ){
    mem5.aiFreelist[iLogsize] = next;    /*将该节点从链表中删除*/
  }else{
    MEM5LINK(prev)->next = next;
  }
  if( next>=0 ){
    MEM5LINK(next)->prev = prev;
  }
}

//将mem5.aPool[i]位置的chunk，插入到空闲链表mem5.aiFreelist[iLogsize]处
static void memsys5Link(int i, int iLogsize){
  int x;
  assert( i>=0 && i<mem5.nBlock );
  assert( iLogsize>=0 && iLogsize<=LOGMAX );
  assert( (mem5.aCtrl[i] & CTRL_LOGSIZE)==iLogsize );

  x = MEM5LINK(i)->next = mem5.aiFreelist[iLogsize];  /*将mem5.aPool[i]位置的chunk，插入到iLogSize链表的头部*/
  MEM5LINK(i)->prev = -1;
  if( x>=0 ){
    assert( x<mem5.nBlock );
    MEM5LINK(x)->prev = i;
  }
  mem5.aiFreelist[iLogsize] = i;
}

//该内存分配器加互斥锁
static void memsys5Enter(void){
  //sqlite3_mutex_enter(mem5.mutex);        /*加互斥锁*/
  printf("获取互斥锁\n");
}
//解锁
static void memsys5Leave(void){
  //sqlite3_mutex_leave(mem5.mutex);        /*退出互斥锁*/
  printf("释放互斥锁\n");
}

//返回一个以字节为单位的未分配的内存大小,省略了8字节大小的头开销
static int memsys5Size(void *p){
  int iSize = 0;
  if( p ){
    int i = ((u8 *)p-mem5.zPool)/mem5.szAtom;
    assert( i>=0 && i<mem5.nBlock );
    iSize = mem5.szAtom * (1 << (mem5.aCtrl[i]&CTRL_LOGSIZE));
  }
  return iSize;
}

//找到空闲链表中的第iLogSize项指向的链表中下标最小的那一项，返回这个下标
static int memsys5UnlinkFirst(int iLogsize){
  int i;
  int iFirst;
  /*iFirst指向下标最小的那一项*/
  assert( iLogsize>=0 && iLogsize<=LOGMAX );   /*判断传入参数的合法性*/
  i = iFirst = mem5.aiFreelist[iLogsize];
  assert( iFirst>=0 );
  while( i>0 ){
    if( i<iFirst ) iFirst = i;
    i = MEM5LINK(i)->next;
  }
  memsys5Unlink(iFirst, iLogsize);
  return iFirst;
}

//给用户分配n字节的空间，返回该空间的地址。
static void *memsys5MallocUnsafe(int nByte){
  int i;           /* Index of a mem5.aPool[] slot aPool的索引*/
  int iBin;        /* Index into mem5.aiFreelist[]  空闲链表的索引*/
  int iFullSz;     /* Size of allocation rounded up to power of 2  内存分配大小四舍五入至2的幂*/
  int iLogsize;    /* Log2 of iFullSz/POW2_MIN */

  assert( nByte>0 );   

  if( (u32)nByte>mem5.maxRequest ){
    mem5.maxRequest = nByte;
  }

  /* Abort if the requested allocation size is larger than the largest
  ** power of two that we can represent using 32-bit signed integers.
  */
  if( nByte > 0x40000000 ){
    return 0;
  }

  /* Round nByte up to the next valid power of two 把nByte的取值到下一个2的幂的有效数*/
  for(iFullSz=mem5.szAtom, iLogsize=0; iFullSz<nByte; iFullSz *= 2, iLogsize++){}

  /* Make sure mem5.aiFreelist[iLogsize] contains at least one free
  ** block.  If not, then split a block of the next larger power of
  ** two in order to create a new free block of size iLogsize.
  */
  for(iBin=iLogsize; mem5.aiFreelist[iBin]<0 && iBin<=LOGMAX; iBin++){}
  if( iBin>LOGMAX ){      /*没有找到这样的项，则返回失败*/
    //testcase( sqlite3GlobalConfig.xLog!=0 );
    //sqlite3_log(SQLITE_NOMEM, "failed to allocate %u bytes", nByte);
    return 0;
  }
  i = memsys5UnlinkFirst(iBin);    /*找到了这样的项，则从freelist中删除*/
  while( iBin>iLogsize ){
    int newSize;

    iBin--;
    newSize = 1 << iBin;
    mem5.aCtrl[i+newSize] = CTRL_FREE | iBin;
    memsys5Link(i+newSize, iBin);
  }
  mem5.aCtrl[i] = iLogsize;

  /* Update allocator performance statistics. */
  mem5.nAlloc++;
  mem5.totalAlloc += iFullSz;
  mem5.totalExcess += iFullSz - nByte;
  mem5.currentCount++;
  mem5.currentOut += iFullSz;
  if( mem5.maxCount<mem5.currentCount ) mem5.maxCount = mem5.currentCount;
  if( mem5.maxOut<mem5.currentOut ) mem5.maxOut = mem5.currentOut;

  /* Return a pointer to the allocated memory. */
  return (void*)&mem5.zPool[i*mem5.szAtom];   /*返回一个指向所分配内存的指针。*/
}

//释放未分配内存，由pOld指针指向的zPool与szAtom的比值，得到要释放的内存块下标
static void memsys5FreeUnsafe(void *pOld){
  u32 size, iLogsize;
  int iBlock;

  /* Set iBlock to the index of the block pointed to by pOld in 
  ** the array of mem5.szAtom byte blocks pointed to by mem5.zPool.
  */
  iBlock = ((u8 *)pOld-mem5.zPool)/mem5.szAtom;   /*设置iBlock为内存块的索引指向 mem5.zPool与mem5.szAtom的比值*/

  /* Check that the pointer pOld points to a valid, non-free block. */
  assert( iBlock>=0 && iBlock<mem5.nBlock );
  assert( ((u8 *)pOld-mem5.zPool)%mem5.szAtom==0 );
  assert( (mem5.aCtrl[iBlock] & CTRL_FREE)==0 );

  iLogsize = mem5.aCtrl[iBlock] & CTRL_LOGSIZE;
  size = 1<<iLogsize;
  assert( iBlock+size-1<(u32)mem5.nBlock );

  mem5.aCtrl[iBlock] |= CTRL_FREE;
  mem5.aCtrl[iBlock+size-1] |= CTRL_FREE;
  assert( mem5.currentCount>0 );
  assert( mem5.currentOut>=(size*mem5.szAtom) );
  mem5.currentCount--;
  mem5.currentOut -= size*mem5.szAtom;
  assert( mem5.currentOut>0 || mem5.currentCount==0 );
  assert( mem5.currentCount>0 || mem5.currentOut==0 );

  mem5.aCtrl[iBlock] = CTRL_FREE | iLogsize;
  while( ALWAYS(iLogsize<LOGMAX) ){
    int iBuddy;
    if( (iBlock>>iLogsize) & 1 ){
      iBuddy = iBlock - size;
    }else{
      iBuddy = iBlock + size;
    }
    assert( iBuddy>=0 );
    if( (iBuddy+(1<<iLogsize))>mem5.nBlock ) break;
    if( mem5.aCtrl[iBuddy]!=(CTRL_FREE | iLogsize) ) break;
    memsys5Unlink(iBuddy, iLogsize);
    iLogsize++;
    if( iBuddy<iBlock ){
      mem5.aCtrl[iBuddy] = CTRL_FREE | iLogsize;
      mem5.aCtrl[iBlock] = 0;
      iBlock = iBuddy;
    }else{
      mem5.aCtrl[iBlock] = CTRL_FREE | iLogsize;
      mem5.aCtrl[iBuddy] = 0;
    }
    size *= 2;
  }
  memsys5Link(iBlock, iLogsize);
}

//申请分配n字节的内存空间。
static void *memsys5Malloc(int nBytes){
  sqlite3_int64 *p = 0;
  if( nBytes>0 ){
    memsys5Enter();
    p = memsys5MallocUnsafe(nBytes);
    memsys5Leave();
  }
  return (void*)p; 
}

//释放*pPrior指向的内存空间。
static void memsys5Free(void *pPrior){
  assert( pPrior!=0 );
  memsys5Enter();
  memsys5FreeUnsafe(pPrior);
  memsys5Leave();  
}

//重新分配*pPrior指向的内存空间大小为n字节。
static void *memsys5Realloc(void *pPrior, int nBytes){
  int nOld;
  void *p;
  assert( pPrior!=0 );
  assert( (nBytes&(nBytes-1))==0 );  /* EV: R-46199-30249 */
  assert( nBytes>=0 );
  if( nBytes==0 ){
    return 0;
  }
  nOld = memsys5Size(pPrior);
  if( nBytes<=nOld ){
    return pPrior;
  }
  memsys5Enter();
  p = memsys5MallocUnsafe(nBytes);
  if( p ){
    memcpy(p, pPrior, nOld);
    memsys5FreeUnsafe(pPrior);
  }
  memsys5Leave();
  return p;
}

//计算当前请求到下一个有效分配的大小。
static int memsys5Roundup(int n){
  int iFullSz;
  if( n > 0x40000000 ) return 0;
  for(iFullSz=mem5.szAtom; iFullSz<n; iFullSz *= 2);
  return iFullSz;
}

//返回最接近iValue的2的幂
static int memsys5Log(int iValue){
  int iLog;
  for(iLog=0; (iLog<(int)((sizeof(int)*8)-1)) && (1<<iLog)<iValue; iLog++);
  return iLog;
}

//初始化该内存分配器。
static int memsys5Init(void *NotUsed){
  int ii;            /* Loop counter 循环计数器*/
  int nByte;         /* Number of bytes of memory available to this allocator 这个分配器可用的内存字节数*/
  u8 *zByte;         /* Memory usable by this allocator 通过这种分配得到的可用内存*/
  int nMinLog;       /* Log base 2 of minimum allocation size in bytes 基于对数2的最小分配的字节数*/
  int iOffset;       /* An offset into mem5.aCtrl[] mem5.aCtrl[]的偏移量*/

  //UNUSED_PARAMETER(NotUsed);

  /* For the purposes of this routine, disable the mutex */
  mem5.mutex = 0;          /*禁用互斥锁*/

  /* The size of a Mem5Link object must be a power of two.  Verify that
  ** this is case.
  ** 
  ** Mem5Link大小的对象必须是2的幂
  */
  assert( (sizeof(Mem5Link)&(sizeof(Mem5Link)-1))==0 ); 

  //nByte = sqlite3GlobalConfig.nHeap;
  nByte = 1024;
  //zByte = (u8*)sqlite3GlobalConfig.pHeap;
  zByte = (u8*) malloc(10240);
  assert( zByte!=0 );  /* sqlite3_config() does not allow otherwise 若zByte==0，则返回*/
  /* boundaries on sqlite3GlobalConfig.mnReq are enforced in sqlite3_config() */
  /*在sqlite3GlobalConfig.mnReq边界强制执行sqlite3_config（）*/
  //nMinLog = memsys5Log(sqlite3GlobalConfig.mnReq);
  //nMinLog = memsys5Log(sqlite3GlobalConfig.mnReq);
  nMinLog = 128;
  mem5.szAtom = (1<<nMinLog);
  while( (int)sizeof(Mem5Link)>mem5.szAtom ){
    mem5.szAtom = mem5.szAtom << 1;
  }

  mem5.nBlock = (nByte / (mem5.szAtom+sizeof(u8)));
  mem5.zPool = zByte;
  mem5.aCtrl = (u8 *)&mem5.zPool[mem5.nBlock*mem5.szAtom];

  for(ii=0; ii<=LOGMAX; ii++){
    mem5.aiFreelist[ii] = -1;
  }

  iOffset = 0;
  for(ii=LOGMAX; ii>=0; ii--){
    int nAlloc = (1<<ii);
    if( (iOffset+nAlloc)<=mem5.nBlock ){
      mem5.aCtrl[iOffset] = ii | CTRL_FREE;
      memsys5Link(iOffset, ii);
      iOffset += nAlloc;
    }
    assert((iOffset+nAlloc)>mem5.nBlock);
  }

  /* If a mutex is required for normal operation, allocate one */
  /*如果程序正常运行需要互斥,则分配一个互斥锁 */
  /*
  if( sqlite3GlobalConfig.bMemstat==0 ){
    mem5.mutex = sqlite3MutexAlloc(SQLITE_MUTEX_STATIC_MEM);
  }
  */

  return SQLITE_OK;
}

//取消模块初始化设置。
static void memsys5Shutdown(void *NotUsed){
  //UNUSED_PARAMETER(NotUsed);
  //mem5.mutex = 0;
  return;
}

#ifdef SQLITE_TEST
//将该内存分配器进行的操作写入日志文件。
void sqlite3Memsys5Dump(const char *zFilename){
  FILE *out;
  int i, j, n;
  int nMinLog;

  if( zFilename==0 || zFilename[0]==0 ){
    out = stdout;
  }else{
    out = fopen(zFilename, "w");
    if( out==0 ){
      fprintf(stderr, "** Unable to output memory debug output log: %s **\n",
                      zFilename);
      return;
    }
  }
  memsys5Enter();
  nMinLog = memsys5Log(mem5.szAtom);
  for(i=0; i<=LOGMAX && i+nMinLog<32; i++){
    for(n=0, j=mem5.aiFreelist[i]; j>=0; j = MEM5LINK(j)->next, n++){}
    fprintf(out, "freelist items of size %d: %d\n", mem5.szAtom << i, n);
  }
  fprintf(out, "mem5.nAlloc       = %llu\n", mem5.nAlloc);
  fprintf(out, "mem5.totalAlloc   = %llu\n", mem5.totalAlloc);
  fprintf(out, "mem5.totalExcess  = %llu\n", mem5.totalExcess);
  fprintf(out, "mem5.currentOut   = %u\n", mem5.currentOut);
  fprintf(out, "mem5.currentCount = %u\n", mem5.currentCount);
  fprintf(out, "mem5.maxOut       = %u\n", mem5.maxOut);
  fprintf(out, "mem5.maxCount     = %u\n", mem5.maxCount);
  fprintf(out, "mem5.maxRequest   = %u\n", mem5.maxRequest);
  memsys5Leave();
  if( out==stdout ){
    fflush(stdout);
  }else{
    fclose(out);
  }
}
#endif

/*
//配置参数
const sqlite3_mem_methods *sqlite3MemGetMemsys5(void){
  static const sqlite3_mem_methods memsys5Methods = {
     memsys5Malloc,
     memsys5Free,
     memsys5Realloc,
     memsys5Size,
     memsys5Roundup,
     memsys5Init,
     memsys5Shutdown,
     0
  };
  return &memsys5Methods;
}
*/

//#endif /* SQLITE_ENABLE_MEMSYS5 */

int main(int argc, char *argv[]){
	void *p = NULL;
	void *p1 = NULL;
	int memSize;
	printf("mem5 test\n");

	printf("初始化内存分配器\n");
	memsys5Init(p);

	printf("分配内存...\n");
	p = memsys5Malloc(8);

	memSize = memsys5Size(p);
	printf("分配内存的大小为:%d\n",memSize);

	printf("调整内存大小\n");
	p1 = memsys5Realloc(p,16);

	memSize = memsys5Size(p1);
	printf("调整后的内存大小为:%d\n",memSize);

	return 0;
}
