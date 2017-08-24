#include <iostream>
#include <stdio.h>
using namespace std;

#pragma pack(4)

void print_sizeof(){
	cout<<"sizeof(char): "<< sizeof(char)<<endl;
	cout<<"sizeof(int): "<<sizeof(int)<<endl;
	cout<<"sizeof(long): "<<sizeof(long)<<endl;
	cout<<"sizeof(double):"<<sizeof(double)<<endl;
}

void print_struct(){
	typedef union { // 公用一段内存
 	   long i;
	   int k[5]; // 4*5 = 20
	   char c;
	} DATE;
	DATE max;

	struct data {
    	int cat;
	    DATE cow;
	    double dog;
	} too;

	cout<<"sizeof(DATE): "<<sizeof(DATE)<<endl; //20
	cout<<"sizeof(max): "<< sizeof(max)<<endl;  //20
	cout<<"sizeof(data): "<< sizeof(data)<<endl;  //32
	cout<<"sizeof(too): "<<sizeof(too)<<endl; //32
}

int main(){
	print_sizeof();
	print_struct();
	return 0;
}
