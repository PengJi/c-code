#include <stdio.h>

/**
 * 字符串转换为整型
 */

int main(){
	char *str1="123";
	char str2[]="4567";
	int num;
	
	printf("size of str1: %d\n", sizeof(str1)); //字符指针的长度
	printf("size of str2: %d\n", sizeof(str2)); //数组的长度

	printf("str1[1]: %c\n", str1[1]);
	printf("str1[1]: %d\n", str1[1]-'0'); //字符转换为整型

	printf("the num is: %d\n", atoi(str1));

	return 0;
}

