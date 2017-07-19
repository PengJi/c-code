#include <stdio.h>
#include <sqlite3.h>
#define LEN 200

int main()
{
	char sql[LEN];
	sqlite3 *db;
	char *err_msg=0;
	int recode;

	sprintf(sql,"create table users(id int identity(1,1) primary key, username var char(10) not null);");

	recode = sqlite3_open("test.db",&db);
	if(recode!=SQLITE_OK)
	{
		printf("Can't Open Database:%s!\n",sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	else
	{
		printf("open OK!\n");
		sqlite3_close(db);
	}
	return 0;
}
