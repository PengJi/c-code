#include <iostream>

using namespace std;

/*
struct 结构名
{
      类型 变量名;
      类型 变量名;
      ...
} 结构变量;

typedef struct 结构名
{
      类型 变量名;
      类型 变量名;
      ...
} 结构别名; 

 */

#pragma pack(4)

struct st1{
	char a;
	int b;
	short c;
};

struct st2{
	short c;
	char a;
	int b;
};

int main(){
	cout<<"sizeof(st1) is "<<sizeof(st1)<<endl;
	cout<<"sizeof(st2) is "<<sizeof(st2)<<endl;
	return 0;
}
