#include <stdio.h>
#include <stdlib.h>

int main(){
	int num = 100;
	char str[25];
	itoa(num,str,10);
	printf("The number is: %s", str);

	return 0;
}
