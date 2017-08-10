#include <iostream>
#include <stdio.h>
using namespace std;

void print_sizeof(){
	cout<<"sizeof(char): "<< sizeof(char)<<endl;
	cout<<"sizeof(int): "<<sizeof(int)<<endl;
	cout<<"sizeof(long): "<<sizeof(long)<<endl;
}

void print_struct(){
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

	cout<<"sizeof(DATE): "<<sizeof(DATE)<<endl;
	cout<<"sizeof(data): "<< sizeof(data)<<endl;
	cout<<"sizeof(max): "<< sizeof(max)<<endl;
	cout<<"sizeof(struct data)+sizeof(max): "<<sizeof(struct data)+sizeof(max)<<endl;
}

int main(){
	print_sizeof();
	print_struct();
	return 0;
}
