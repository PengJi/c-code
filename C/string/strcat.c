#include <stdio.h>
#include <string.h>

/**
 * 字符串拼接
 */

int main(){
	char str[10];
	strcpy(str,"these ");
	strcat(str,"strings ");
	strcat(str,"are ");
	strcat(str,"concatenated.");

	printf("The string is: %s\n",str);

	return 0;
}
