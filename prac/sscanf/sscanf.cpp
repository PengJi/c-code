#include <iostream>

using namespace std;

//Ω‚ŒˆÕ¯÷∑
int main(){
	const char *s = "http://www.baidu.com:1234";
    char protocol[32] = { 0 };
    char host[128] = { 0 };
    char port[8] = { 0 };
    sscanf(s,"%[^:]://%[^:]:%[1-9]",protocol,host,port);
 
    printf("protocol: %s\n",protocol);
    printf("host: %s\n",host);
    printf("port: %s\n",port);

	return 0;

}
