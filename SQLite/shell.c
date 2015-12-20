#include <stdio.h>
#include <sqlite3.h>

int main()
{
    sqlite3 *db = NULL;
    int result;
    result = sqlite3_open("test.db", &db);
    if (SQLITE_OK != result)
    {
        printf("Create/Open test.db error! \n");
    }
    printf("Create/Open test.db success!! \n");
	
    const char* sqlStr1 = "create table table2(sid integer primary key not null,age string);";
    result = sqlite3_exec(db, sqlStr1, 0, 0, 0);
    if (SQLITE_OK != result)
    {
        printf("create table table1 error! \n");
        return 0;
    }
    printf("create table table1 success! \n");
    const char* sqlStr2 = "insert into table1() values(1,'name1');";
    result = sqlite3_exec(db, sqlStr2, 0, 0, 0);
    if (SQLITE_OK != result)
    {
        printf("insert table table1 error! \n");
        return 0;
    }
    printf("insert table table1 success! \n");
    sqlite3_close(db);
    return 0;
}
