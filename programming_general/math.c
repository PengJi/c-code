#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[]){

	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
	double result;

	result = pow(base,exponent);
	printf("%g ^ %d is %g\n",base,exponent,result);

	return 0;
}
