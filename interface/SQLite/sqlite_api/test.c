#include "test.h"

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }   
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int  rc; 
	char *sql;
	const char* data = "Callback function called";
	sqlite3_int64 used;
	sqlite3_int64 highwater;
	int status;

	/*set memory allocator */
	status = sqlite3_config(SQLITE_CONFIG_MEMSTATUS,1);
	if(status == SQLITE_OK){
		printf(L_CYAN "enable the memory allocation status collection logic\n");
	}else{
		printf(L_PURPLE "not enable the memory allocation status collection logic\n");
	}
	/*
	void *p = malloc(80000);
	status = sqlite3_config(SQLITE_CONFIG_HEAP,p,80001,8);
	if(status == SQLITE_OK){
		printf(L_CYAN "switch memory allocator successfully!\n");
	}else{
		printf(L_PURPLE "switch memory allocator unsuccessfully!\n");
	}
	*/

	/*calculate memory use*/
	used =  sqlite3_memory_used();
	highwater = sqlite3_memory_highwater(0);
	printf(L_GREEN "not running\n");
	printf( RED "memory used: %d\n",used);
	printf( YELLOW "memory highwater: %d\n",highwater);
	printf("\e[0m\n",  __LINE__);

	/* Open database */
	rc = sqlite3_open("test.db", &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}else{
		fprintf(stdout, "Opened database successfully\n");
	}

	/* calculate memory use */
	used =  sqlite3_memory_used();
	highwater = sqlite3_memory_highwater(0);
	printf(L_GREEN "open database\n");
	printf(RED "memory used: %d\n",used);
    printf( YELLOW "memory highwater: %d\n",highwater);
	printf("\e[0m\n",  __LINE__);

	/* Create SQL statement */
	sql = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
	fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Table created successfully\n");
	}

	/*calculate memory use*/
    used =  sqlite3_memory_used();
	highwater = sqlite3_memory_highwater(0);
	printf(L_GREEN "create table\n");
    printf( RED "memory used: %d\n",used);
	printf( YELLOW "memory highwater: %d\n",highwater);
    printf("\e[0m\n",  __LINE__);

	/* Create SQL statement */
	sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "  \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Records created successfully\n");
	}

	/*calculate memory use*/
    used =  sqlite3_memory_used();
	highwater = sqlite3_memory_highwater(0);
	printf(L_GREEN "insert operation\n");
    printf( RED "memory used: %d\n",used);
	printf( YELLOW "memory highwater: %d\n",highwater);
    printf("\e[0m\n",  __LINE__);

	/* Create SQL statement */
	sql = "SELECT * from COMPANY";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Operation done successfully\n");
	}

	/*calculate memory use*/
    used =  sqlite3_memory_used();
	highwater = sqlite3_memory_highwater(0);
	printf(L_GREEN "select operation\n");
    printf( RED "memory used: %d\n",used);
	printf( YELLOW "memory highwater: %d\n",highwater);
    printf("\e[0m\n",  __LINE__);

	/* Create merged SQL statement */
	sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
         "SELECT * from COMPANY";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Operation done successfully\n");
	}

	/*calculate memory use*/
    used =  sqlite3_memory_used();
	highwater = sqlite3_memory_highwater(0);
	printf(L_GREEN "update operation\n");
    printf( RED "memory used: %d\n",used);
	printf( YELLOW "memory highwater: %d\n",highwater);
    printf("\e[0m\n",  __LINE__);

	/* Create merged SQL statement */
	sql = "DELETE from COMPANY where ID=2; " \
         "SELECT * from COMPANY";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Operation done successfully\n");
	}

	/*calculate memory use*/
    used =  sqlite3_memory_used();
	highwater = sqlite3_memory_highwater(0);
	printf(L_GREEN "delete operation\n");highwater = sqlite3_memory_highwater(0);
    printf( RED "memory used: %d\n",used);
	printf( YELLOW "memory highwater: %d\n",highwater);
    printf("\e[0m\n",  __LINE__);

	sqlite3_close(db);
	return 0;  

}
