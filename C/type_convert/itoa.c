#include <stdio.h>
#include <stdlib.h>

int main(){
	int num = 100, fl = 1.1;
	char str[25];

	//整型转字符串
	snprintf(str,sizeof(num),"%d",num);
	printf("The number is(snprintf): %s\n",str);
	
	//整型转字符串
	num = 99;
	sprintf(str,"%d",num);
	printf("The number is(sprintf): %s\n",str);

	//itoa(num,str,10);
	//printf("The number is: %s", str);
	
	sprintf(str,"%g",fl);
	printf("convert float to char: %s\n", str);

	return 0;
}
