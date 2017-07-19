#include "mem_alloc.h"

static void *sqlite3MemMalloc(int nByte){ return 0; }

static void sqlite3MemFree(void *pPrior){ return; }

static void *sqlite3MemRealloc(void *pPrior, int nByte){ return 0; }

static int sqlite3MemSize(void *pPrior){ return 0; }

static int sqlite3MemRoundup(int n){ return n; }

static int sqlite3MemInit(void *NotUsed){ return SQLITE_OK; }

static void sqlite3MemShutdown(void *NotUsed){ return; }
