#include <iostream>
#include <stdio.h>
using namespace std;

void print_sizeof(){
	typedef union {
 	   long i;
	    int k[5];
	    char c;
	} DATE;
	struct data {
    	int cat;
	    DATE cow;
	    double dog;
	} too;
	DATE max;

	printf("%d",sizeof(struct data)+sizeof(max));

}

int main(){
	print_sizeof();
	return 0;
}
