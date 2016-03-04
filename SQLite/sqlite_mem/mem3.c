#include "tmp.h"

//#ifdef SQLITE_ENABLE_MEMSYS3   //宏定义触发该内存分配子系统被组建到库中

#define MX_SMALL 10    //Mem3Blocks中的一个块

#define N_HASH  61    //自由列表中hash slots的个数

typedef struct Mem3Block Mem3Block;   //定义一个任意类型的数据块结构体
struct Mem3Block {
  union {       //联合体，它里面定义的每个变量使用同一段内存空间，达到节约空间的目的
    struct {
      u32 prevSize;   /* Size of previous chunk in Mem3Block elements  前一个chunk的大小 */
      u32 size4x;     /* 4x the size of current chunk in Mem3Block elements  当前chunk大小的4倍 */
    } hdr;    //chunk中的第一个block名为hdr，不返回给用户
    struct {
      u32 next;       /* Index in mem3.aPool[] of next free chunk  下一个未使用chunk的索引号 */
      u32 prev;       /* Index in mem3.aPool[] of previous free chunk  前一个未使用chunk的索引号 */
    } list;   //chunk中的第二个block名为list
  } u;   //定义了一个名为u的chunk
};

struct Mem3Global {
  u32 nPool;   //内存变量数组分配的空间大小
  Mem3Block *aPool;//指向Mem3Block类型变量的指针

  int alarmBusy;  //为真时进行内存回收
  
  //sqlite3_mutex *mutex;    //控制内存分配子系统的访问
  int *mutex;
  
  u32 mnMaster;    //最小可分配空闲空间的大小

  u32 iMaster;  //新分配的chunk的索引号
  u32 szMaster;  //当前chunk的大小(block的数目)，不构成双链表

  u32 aiSmall[MX_SMALL-1]; /* For sizes 2 through MX_SMALL, inclusive  双链表中较小的chunk数组 */
  u32 aiHash[N_HASH];        /* For sizes MX_SMALL+1 and larger  较大chunk */
} mem3 = { 97535575 };//定义一个名为mem3的全局变量并赋值

//#define mem3 GLOBAL(struct Mem3Global, mem3)

//将第i个项从双向链表中删除， 如果是第一个，则调整pRoot指针；
//同时调整 前一个的next指针，和后一个的prev指针。将卸下来的这一项的prev和next都设置为null。               
static void memsys3UnlinkFromList(u32 i, u32 *pRoot){
  u32 next = mem3.aPool[i].u.list.next;  //将索引号为aPool[i]的块的下一个块索引号赋值给next
  u32 prev = mem3.aPool[i].u.list.prev;  //将索引号为aPool[i]的块的前一个块索引号赋给prev
  //assert( sqlite3_mutex_held(mem3.mutex) );//若当前有互斥锁，则终止程序
  if( prev==0 ){    //若当前chunk的前一个chunk不存在
    *pRoot = next;     //将指针pRoot指向下一个chunk的 索引号
  }else{ 
    mem3.aPool[prev].u.list.next = next;//否则将当前chunk的next赋给前一个chunk的下一个chunk
  }
  if( next ){
    mem3.aPool[next].u.list.prev = prev;
  }
  mem3.aPool[i].u.list.next = 0;
  mem3.aPool[i].u.list.prev = 0; //将当前使用的chunk从list中移出，前后指向为0表示没有该块
}

//从双向循环链表中删除第i项。  
static void memsys3Unlink(u32 i){
  u32 size, hash;
  //assert( sqlite3_mutex_held(mem3.mutex) );
  assert( (mem3.aPool[i-1].u.hdr.size4x & 1)==0 );  
  assert( i>=1 );                              
  size = mem3.aPool[i-1].u.hdr.size4x/4;

  assert( size==mem3.aPool[i+size-1].u.hdr.prevSize );
  assert( size>=2 );               
  if( size <= MX_SMALL ){
    memsys3UnlinkFromList(i, &mem3.aiSmall[size-2]);
  }else{
    hash = size % N_HASH;
    memsys3UnlinkFromList(i, &mem3.aiHash[hash]);
  }
}

//将mem3.aPool[i]插入到pRoot指向的链表的头部，更新pRoot指向新插入的这一项。
static void memsys3LinkIntoList(u32 i, u32 *pRoot){
  //assert( sqlite3_mutex_held(mem3.mutex) );
  mem3.aPool[i].u.list.next = *pRoot;   //索引号为i的块的下一块索引号设为*pRoot
  mem3.aPool[i].u.list.prev = 0;   //将索引号为i的前一块索引号设置为0
  if( *pRoot ){
  mem3.aPool[*pRoot].u.list.prev = i;//若*pRoot存在，则i的值设为该索引号对应块的前一块
  }
  *pRoot = i;
} 

//将第i项插入链表中。
static void memsys3Link(u32 i){
  u32 size, hash;
  //assert( sqlite3_mutex_held(mem3.mutex) );
  assert( i>=1 );    
  assert( (mem3.aPool[i-1].u.hdr.size4x & 1)==0 );
  size = mem3.aPool[i-1].u.hdr.size4x/4;  //用来判断是block还是chunk
  assert( size==mem3.aPool[i+size-1].u.hdr.prevSize );
  assert( size>=2 );               //若只是一个block，则终止程序
  if( size <= MX_SMALL ){
    memsys3LinkIntoList(i, &mem3.aiSmall[size-2]);  //如果size小于10，将i块加入小chunk
  }else{
    hash = size % N_HASH;
    memsys3LinkIntoList(i, &mem3.aiHash[hash]);  //将i块加入大chunk
  }
}

//该函数用于获取互斥锁,通过sqlite3GlobalConfig.bMemstat的值来判断是否已经获取
static void memsys3Enter(void){
/*
  if( sqlite3GlobalConfig.bMemstat==0 && mem3.mutex==0 ){//判断是否已经获得互斥锁
    mem3.mutex = sqlite3MutexAlloc(SQLITE_MUTEX_STATIC_MEM);//获取互斥锁
  }
  sqlite3_mutex_enter(mem3.mutex);     //加锁
  */
	printf("获取互斥锁\n");
}
static void memsys3Leave(void){
  //sqlite3_mutex_leave(mem3.mutex);    //释放锁
  printf("释放互斥锁\n");
}

//注意！！！
//分配的内存不足时释放n字节空间。
static void memsys3OutOfMemory(int nByte){
  if( !mem3.alarmBusy ){  //mem3.alarmBusy为假时进行内存回收
    mem3.alarmBusy = 1;  //赋值为1表示进行内存回收
    //assert( sqlite3_mutex_held(mem3.mutex) );
    //sqlite3_mutex_leave(mem3.mutex); //释放互斥锁
    //sqlite3_release_memory(nByte);  //释放n字节内存
    //sqlite3_mutex_enter(mem3.mutex);  //加锁
    mem3.alarmBusy = 0;  //回收完毕
  }
}

//调整第i块的大小为nblock，为用户使用，返回该空间的地址。
static void *memsys3Checkout(u32 i, u32 nBlock){
  u32 x;
  //assert( sqlite3_mutex_held(mem3.mutex) );
  assert( i>=1 );  //该块不存在则终止程序
  assert( mem3.aPool[i-1].u.hdr.size4x/4==nBlock ); 
  assert( mem3.aPool[i+nBlock-1].u.hdr.prevSize==nBlock );
  x = mem3.aPool[i-1].u.hdr.size4x;
  mem3.aPool[i-1].u.hdr.size4x = nBlock*4 | 1 | (x&2);  //调整块大小，并置当前chunk为已使用
  mem3.aPool[i+nBlock-1].u.hdr.prevSize = nBlock;
  mem3.aPool[i+nBlock-1].u.hdr.size4x |= 2;  //置前一chunk为已使用
  return &mem3.aPool[i];    //返回一个指向用户使用该块处的指针
}

//从iMaster开始的大chunk上切下nBlock的chunk供用户使用，返回该空间的地址。
static void *memsys3FromMaster(u32 nBlock){
  //assert( sqlite3_mutex_held(mem3.mutex) ); 
  assert( mem3.szMaster>=nBlock );  //主要块的大小若小于nBlock，则终止程序
  if( nBlock>=mem3.szMaster-1 ){   //若nBlock等于该主要块大小，则使用整个主chunk
    /* Use the entire master */
    void *p = memsys3Checkout(mem3.iMaster, mem3.szMaster);
    mem3.iMaster = 0;
    mem3.szMaster = 0;
    mem3.mnMaster = 0;
    return p;
  }else{       //若nBlock小于主chunk大小，则分裂master free chunk，返回尾部地址
    /* Split the master block.  Return the tail. */
    u32 newi, x;
    newi = mem3.iMaster + mem3.szMaster - nBlock; //将多出来的空间赋给newi
    assert( newi > mem3.iMaster+1 ); //除去nBlock大小外的空间小于等于mem3.iMaster，则终止
    mem3.aPool[mem3.iMaster+mem3.szMaster-1].u.hdr.prevSize = nBlock;//分裂出的chunk
    mem3.aPool[mem3.iMaster+mem3.szMaster-1].u.hdr.size4x |= 2;  //置前一块为已使用
    mem3.aPool[newi-1].u.hdr.size4x = nBlock*4 + 1;
    mem3.szMaster -= nBlock;       //当前chunk大小为nBlock
    mem3.aPool[newi-1].u.hdr.prevSize = mem3.szMaster; //剩余部分的前一块大小也即为nBlock
    x = mem3.aPool[mem3.iMaster-1].u.hdr.size4x & 2;
    mem3.aPool[mem3.iMaster-1].u.hdr.size4x = mem3.szMaster*4 | x;
    if( mem3.szMaster < mem3.mnMaster ){ //若当前chunk空间小于块中的最小空间，则将最小空间大小赋值为当前块空间大小
      mem3.mnMaster = mem3.szMaster;
    }
    return (void*)&mem3.aPool[newi];  //返回新空间地址
  }
} 

//该函数用于合并每一个chunk入口，*pRoot是chunk列表的头指针
//合并相邻chunk块到*pRoot指向的链表中，若块大于当前master，则将其替换。
static void memsys3Merge(u32 *pRoot){
  u32 iNext, prev, size, i, x;

  //assert( sqlite3_mutex_held(mem3.mutex) );
  for(i=*pRoot; i>0; i=iNext){       //循环查找chunk列表中的chunk
    iNext = mem3.aPool[i].u.list.next;  //使iNext为aPool[i]的下一个chunk的索引号
    size = mem3.aPool[i-1].u.hdr.size4x; //size存储aPool[i-1]索引号对应块的大小
    assert( (size&1)==0 );
    if( (size&2)==0 ){
      memsys3UnlinkFromList(i, pRoot); 
      assert( i > mem3.aPool[i-1].u.hdr.prevSize );
      prev = i - mem3.aPool[i-1].u.hdr.prevSize;
      if( prev==iNext ){
        iNext = mem3.aPool[prev].u.list.next;
      }
      memsys3Unlink(prev);
      size = i + size/4 - prev;
      x = mem3.aPool[prev-1].u.hdr.size4x & 2;
      mem3.aPool[prev-1].u.hdr.size4x = size*4 | x;
      mem3.aPool[prev+size-1].u.hdr.prevSize = size;
      memsys3Link(prev);
      i = prev;
    }else{
      size /= 4;
    }
    if( size>mem3.szMaster ){
      mem3.iMaster = i;
      mem3.szMaster = size;
    }
  }
}

//给用户分配n字节的空间，返回该空间的地址。
//该函数返回至少n字节大小的block，没有则返回null。该函数假设所有必要的互斥锁都上了，所以不安全
static void *memsys3MallocUnsafe(int nByte){
  u32 i;
  u32 nBlock;
  u32 toFree;

  //assert( sqlite3_mutex_held(mem3.mutex) );   //如果不能加锁，则终止程序
  assert( sizeof(Mem3Block)==8 );   //若Mem3Block大小为8，继续往下执行
  if( nByte<=12 ){                //给nBlock赋值
    nBlock = 2;
  }else{
    nBlock = (nByte + 11)/8;
  }
  assert( nBlock>=2 );

  /* STEP 1:
  ** Look for an entry of the correct size in either the small
  ** chunk table or in the large chunk hash table.  This is
  ** successful most of the time (about 9 times out of 10).
  */   
  //首先在小chunk或者大chunk中寻找正确大小块的入口，一般都会成功
  if( nBlock <= MX_SMALL ){        //nBlock小于MX_SMALL，则在小chunk中找
    i = mem3.aiSmall[nBlock-2];
    if( i>0 ){
      memsys3UnlinkFromList(i, &mem3.aiSmall[nBlock-2]);
      return memsys3Checkout(i, nBlock);  //返回找到的满足的chunk
    }
  }else{    //若nBlock大于MX_SMALL，则在大chunk中找
    int hash = nBlock % N_HASH;
    for(i=mem3.aiHash[hash]; i>0; i=mem3.aPool[i].u.list.next){
      if( mem3.aPool[i-1].u.hdr.size4x/4==nBlock ){
        memsys3UnlinkFromList(i, &mem3.aiHash[hash]);
        return memsys3Checkout(i, nBlock);   //返回找到的chunk
      }
    }
  }

  /* STEP 2:
  ** Try to satisfy the allocation by carving a piece off of the end
  ** of the master chunk.  This step usually works if step 1 fails.
  */     
  //尝试从master chunk中分裂出合适的空间，第一步失败才执行
  if( mem3.szMaster>=nBlock ){
    return memsys3FromMaster(nBlock);  //从master chunk中获取chunk
  }


  /* STEP 3:  
  ** Loop through the entire memory pool.  Coalesce adjacent free
  ** chunks.  Recompute the master chunk as the largest free chunk.
  ** Then try again to satisfy the allocation by carving a piece off
  ** of the end of the master chunk.  This step happens very
  ** rarely (we hope!)
  */
  //遍历整个内存池，合并相邻空闲chunk，重新计算主要的chunk大小，
  //再次尝试从master chunk中分裂出满足分配条件的chunk。前面都不行才执行该步骤。
  for(toFree=nBlock*16; toFree<(mem3.nPool*16); toFree *= 2){  //遍历内存池
    memsys3OutOfMemory(toFree);     //不够分配则释放
    if( mem3.iMaster ){               //master chunk存在，将其链接到相应块索引表中        
      memsys3Link(mem3.iMaster);
      mem3.iMaster = 0;
      mem3.szMaster = 0;
    }
    for(i=0; i<N_HASH; i++){
      memsys3Merge(&mem3.aiHash[i]);  //链接相邻空chunk到aiHash中
    }
    for(i=0; i<MX_SMALL-1; i++){
      memsys3Merge(&mem3.aiSmall[i]); //链接相邻空chunk到aiSmall中
    }
    if( mem3.szMaster ){             //当前master chunk不为0，则从索引表中断开
      memsys3Unlink(mem3.iMaster);
      if( mem3.szMaster>=nBlock ){
        return memsys3FromMaster(nBlock); //返回得到的内存空间
      }
    }
  }

  /* If none of the above worked, then we fail. */ 
  return 0;  //若上面三步都失败了，那就失败了，返回0
} 

//释放内存空间。
static void memsys3FreeUnsafe(void *pOld){//*pOld指向为完成分配的内存空间
  Mem3Block *p = (Mem3Block*)pOld;
  int i;
  u32 size, x;
  //assert( sqlite3_mutex_held(mem3.mutex) );
  assert( p>mem3.aPool && p<&mem3.aPool[mem3.nPool] );
  i = p - mem3.aPool;
  assert( (mem3.aPool[i-1].u.hdr.size4x&1)==1 );
  size = mem3.aPool[i-1].u.hdr.size4x/4;
  assert( i+size<=mem3.nPool+1 );
  mem3.aPool[i-1].u.hdr.size4x &= ~1;
  mem3.aPool[i+size-1].u.hdr.prevSize = size;
  mem3.aPool[i+size-1].u.hdr.size4x &= ~2;
  memsys3Link(i);  //将索引号为i的chunk链接到合适的chunk数组中

  /* Try to expand the master using the newly freed chunk */
  //尝试使用释放了的chunk扩大主要的chunk大小
  if( mem3.iMaster ){
    while( (mem3.aPool[mem3.iMaster-1].u.hdr.size4x&2)==0 ){
      size = mem3.aPool[mem3.iMaster-1].u.hdr.prevSize;
      mem3.iMaster -= size;
      mem3.szMaster += size;
      memsys3Unlink(mem3.iMaster);
      x = mem3.aPool[mem3.iMaster-1].u.hdr.size4x & 2;
      mem3.aPool[mem3.iMaster-1].u.hdr.size4x = mem3.szMaster*4 | x;
      mem3.aPool[mem3.iMaster+mem3.szMaster-1].u.hdr.prevSize = mem3.szMaster;
    }
    x = mem3.aPool[mem3.iMaster-1].u.hdr.size4x & 2;
    while( (mem3.aPool[mem3.iMaster+mem3.szMaster-1].u.hdr.size4x&1)==0 ){
      memsys3Unlink(mem3.iMaster+mem3.szMaster);
      mem3.szMaster += mem3.aPool[mem3.iMaster+mem3.szMaster-1].u.hdr.size4x/4;
      mem3.aPool[mem3.iMaster-1].u.hdr.size4x = mem3.szMaster*4 | x;
      mem3.aPool[mem3.iMaster+mem3.szMaster-1].u.hdr.prevSize = mem3.szMaster;
    }
  }
}

//以字节返回未分配内存大小（头8字节除外）。
static int memsys3Size(void *p){
  Mem3Block *pBlock;
  if( p==0 ) return 0;
  pBlock = (Mem3Block*)p;
  assert( (pBlock[-1].u.hdr.size4x&1)!=0 );
  return (pBlock[-1].u.hdr.size4x&~3)*2 - 4;
}

//聚集请求大小给下一个有效的内存分配大小。
static int memsys3Roundup(int n){
  if( n<=12 ){
    return 12;
  }else{
    return ((n+11)&~7) - 4;
  }
}

//申请分配n字节的内存空间。
static void *memsys3Malloc(int nBytes){//分配n字节的内存
  sqlite3_int64 *p;
  assert( nBytes>0 );          /* malloc.c filters out 0 byte requests *///请求字节为0则终止程序
  memsys3Enter();          //获取共享锁
  p = memsys3MallocUnsafe(nBytes);   //分配内存
  memsys3Leave();    //释放锁
  return (void*)p;    //返回空指针
}

//释放*pPrior指向的内存空间。
static void memsys3Free(void *pPrior){
  assert( pPrior );
  memsys3Enter();                //加锁
  memsys3FreeUnsafe(pPrior);      //释放内存
  memsys3Leave();              //解锁
}

//重新分配*pPrior指向的内存空间大小为n字节。
static void *memsys3Realloc(void *pPrior, int nBytes){
  int nOld;
  void *p;
  /*
  if( pPrior==0 ){              //原来的内存为0，则直接分配n字节
    return sqlite3_malloc(nBytes);
  }
  if( nBytes<=0 ){    
    sqlite3_free(pPrior);  //释放从由sqlite3Malloc获得的内存空间
    return 0;
  }
  */
  nOld = memsys3Size(pPrior);  //获取未完成分配的内存空间
  if( nBytes<=nOld && nBytes>=nOld-128 ){
    return pPrior;
  }
  memsys3Enter();              
  p = memsys3MallocUnsafe(nBytes);     //申请n字节的内存空间
  if( p ){
    if( nOld<nBytes ){
      memcpy(p, pPrior, nOld);
    }else{
      memcpy(p, pPrior, nBytes);
    }
    memsys3FreeUnsafe(pPrior);
  }
  memsys3Leave();
  return p;
}

static int memsys3Init(void *NotUsed){
  //UNUSED_PARAMETER(NotUsed);
  /*
  if( !sqlite3GlobalConfig.pHeap ){
    return SQLITE_ERROR;
  }
  */

  /* Store a pointer to the memory block in global structure mem3. */
  //在结构体mem3中存储一个指向该内存块的指针
  assert( sizeof(Mem3Block)==8 ); //若该内存块大小为8字节，继续执行
  //mem3.aPool = (Mem3Block *)sqlite3GlobalConfig.pHeap;
  mem3.aPool = (Mem3Block *)malloc(10240);//分配内存
  //mem3.nPool = (sqlite3GlobalConfig.nHeap / sizeof(Mem3Block)) - 2;
  mem3.nPool = (1024 / sizeof(Mem3Block)) - 2;//个数

  /* Initialize the master block. */  //初始化master chunk
  mem3.szMaster = mem3.nPool;
  mem3.mnMaster = mem3.szMaster;
  mem3.iMaster = 1;
  mem3.aPool[0].u.hdr.size4x = (mem3.szMaster<<2) + 2;
  mem3.aPool[mem3.nPool].u.hdr.prevSize = mem3.nPool;
  mem3.aPool[mem3.nPool].u.hdr.size4x = 1;

  return SQLITE_OK;
} 

static void memsys3Shutdown(void *NotUsed){
  //UNUSED_PARAMETER(NotUsed);
  mem3.mutex = 0;
  return;
}

//将该内存分配器进行的操作写入日志文件。
void sqlite3Memsys3Dump(const char *zFilename){
#ifdef SQLITE_DEBUG
  FILE *out;
  u32 i, j;
  u32 size;
 if( zFilename==0 || zFilename[0]==0 ){//若文件夹不存在或文件夹中没有内容，则输出设为stdout
    out = stdout;
  }else{   
    out = fopen(zFilename, "w");   //以可写的方式打开该文件
    if( out==0 ){          //若没有输出内容，将提示信息写到文件中     
      fprintf(stderr, "** Unable to output memory debug output log: %s **\n",
                      zFilename);
      return;
    }
  }
  memsys3Enter();
  fprintf(out, "CHUNKS:\n");  //打印提示信息
  for(i=1; i<=mem3.nPool; i+=size/4){        //遍历可分配内存块
    size = mem3.aPool[i-1].u.hdr.size4x;
    if( size/4<=1 ){
      fprintf(out, "%p size error\n", &mem3.aPool[i]); //内存空间错误
      assert( 0 );
      break;
    }
    if( (size&1)==0 && mem3.aPool[i+size/4-1].u.hdr.prevSize!=size/4 ){
      fprintf(out, "%p tail size does not match\n", &mem3.aPool[i]);  //结尾块大小不正确
      assert( 0 );
      break;
    }
    if( ((mem3.aPool[i+size/4-1].u.hdr.size4x&2)>>1)!=(size&1) ){
      fprintf(out, "%p tail checkout bit is incorrect\n", &mem3.aPool[i]); //结尾块不正确
      assert( 0 );
      break;
    }
    if( size&1 ){
      fprintf(out, "%p %6d bytes checked out\n", &mem3.aPool[i], (size/4)*8-8); //检查完
    }else{
      fprintf(out, "%p %6d bytes free%s\n", &mem3.aPool[i], (size/4)*8-8,
                  i==mem3.iMaster ? " **master**" : "");
    }
  }
  for(i=0; i<MX_SMALL-1; i++){
    if( mem3.aiSmall[i]==0 ) continue;
    fprintf(out, "small(%2d):", i);
    for(j = mem3.aiSmall[i]; j>0; j=mem3.aPool[j].u.list.next){
      fprintf(out, " %p(%d)", &mem3.aPool[j],
              (mem3.aPool[j-1].u.hdr.size4x/4)*8-8);
    }
    fprintf(out, "\n"); 
  }
  for(i=0; i<N_HASH; i++){
    if( mem3.aiHash[i]==0 ) continue;
    fprintf(out, "hash(%2d):", i);
    for(j = mem3.aiHash[i]; j>0; j=mem3.aPool[j].u.list.next){
      fprintf(out, " %p(%d)", &mem3.aPool[j],
              (mem3.aPool[j-1].u.hdr.size4x/4)*8-8);
    }
    fprintf(out, "\n"); 
  }
  fprintf(out, "master=%d\n", mem3.iMaster);
  fprintf(out, "nowUsed=%d\n", mem3.nPool*8 - mem3.szMaster*8);
  fprintf(out, "mxUsed=%d\n", mem3.nPool*8 - mem3.mnMaster*8);
  sqlite3_mutex_leave(mem3.mutex);
  if( out==stdout ){
    fflush(stdout);
  }else{
    fclose(out);
  }
#else
  //UNUSED_PARAMETER(zFilename);
#endif
}

/* 
//配置参数
const sqlite3_mem_methods *sqlite3MemGetMemsys3(void){
  static const sqlite3_mem_methods mempoolMethods = {
     memsys3Malloc,
     memsys3Free,
     memsys3Realloc,
     memsys3Size,
     memsys3Roundup,
     memsys3Init,
     memsys3Shutdown,
     0
  };
  return &mempoolMethods;
}
*/

//#endif /* SQLITE_ENABLE_MEMSYS3 */


int main(){
	void *p = NULL;
	void *p1 = NULL;
	int status,memSize;
	printf("mem3 test\n");
	
	status = memsys3Init(p);

	printf("分配内存...\n");
	p = memsys3Malloc(8);

	memSize = memsys3Size(p);
	printf("分配内存的大小为:%d\n",memSize);

	printf("重新分配内存大小...\n");
	p1 = memsys3Realloc(p,16);

	memSize = memsys3Size(p1);
	printf("调整后的内存大小为:%d\n",memSize);

	printf("释放内存...\n");
	memsys3Free(p1);

	return 0;
}
