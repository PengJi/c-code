#include <stdio.h>
#include <stdlib.h>

int main(){
	int num = 100;
	char str[25];

	snprintf(str,sizeof(num),"%d",num);
	printf("The number is(snprintf): %s\n",str);
	
	num = 99;
	sprintf(str,"%d",num);
	printf("The number is(sprintf): %s\n",str);

	//itoa(num,str,10);
	//printf("The number is: %s", str);

	return 0;
}
