#include <stdio.h>

int main(){
	int a = 10;
	int *b = &a;
	printf("*b: %d\n",*b);
	printf("b: %ld\n",b);

	return 0;
}
