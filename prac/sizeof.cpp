#include <iostream>
#include <stdio.h>
using namespace std;

void print_sizeof(){
	cout<<"sizeof(char): "<< sizeof(char)<<endl;
	cout<<"sizeof(int): "<<sizeof(int)<<endl;
	cout<<"sizeof(long): "<<sizeof(long)<<endl;
	cout<<"sizeof(double):"<<sizeof(double)<<endl;
}

void print_struct(){
	typedef union {
 	   long i;
	   int k[5];
	   char c;
	} DATE;
	DATE max;

	struct data {
    	int cat;
	    DATE cow;
	    double dog;
	} too;

	cout<<"sizeof(DATE): "<<sizeof(DATE)<<endl; //24
	cout<<"sizeof(max): "<< sizeof(max)<<endl;  //24
	cout<<"sizeof(data): "<< sizeof(data)<<endl;  //40
	cout<<"sizeof(too): "<<sizeof(too)<<endl; //40
}

int main(){
	print_sizeof();
	print_struct();
	return 0;
}
