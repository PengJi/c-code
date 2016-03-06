#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/*
static void *sqlite3MemMalloc(int nByte);
static void sqlite3MemFree(void *pPrior);
static void *sqlite3MemRealloc(void *pPrior, int nByte);
static int sqlite3MemSize(void *pPrior);
static int sqlite3MemRoundup(int n);
static int sqlite3MemInit(void *NotUsed);
static void sqlite3MemShutdown(void *NotUsed);
*/

static void *sqlite3MemMalloc(int nByte){ return 0; }

static void sqlite3MemFree(void *pPrior){ return; }

static void *sqlite3MemRealloc(void *pPrior, int nByte){ return 0; }

static int sqlite3MemSize(void *pPrior){ return 0; }

static int sqlite3MemRoundup(int n){ return n; }

static int sqlite3MemInit(void *NotUsed){ return SQLITE_OK; }

static void sqlite3MemShutdown(void *NotUsed){ return; }


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

