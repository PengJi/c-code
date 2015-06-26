#include <iostream>

using namespace std;

int main(){
	char str[256] = { 0 };
    int data = 1024;

    //将data转换为字符串
    sprintf(str,"%d",data);
	printf("字符串：%s\n",str);

    //获取data的十六进制
    sprintf(str,"0x%X",data);
	printf("十六进制：%s\n",str);

    //获取data的八进制
    sprintf(str,"0%o",data);
	printf("八进制：%s\n",str);

    const char *s1 = "Hello";
    const char *s2 = "World";

    //连接字符串s1和s2
    sprintf(str,"%s %s",s1,s2);
	printf("链接字符串：%s\n",str);

	return 0;
}