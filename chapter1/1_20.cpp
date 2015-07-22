#include<iostream>
#include<stdlib.h>
using namespace std;
#define N  10
double polynomail(int a[],int i,double x,int n)
{
	if(i>0) 
		return a[n-i]+polynomail(a,i-1,x,n)*x;
	else 
		return a[n];
}
int main()
{
    double x;
	int n,i;
	int a[N];
	cout<<"请输入变量的值x:";
	cin>>x;
	cout<<"请输入多项式的阶次n:";
	cin>>n;
	if(n>N-1) exit(0);
	cout<<"请输入多项式的系数a[0]--a[n]:";
	for(i=0;i<=n;i++) cin>>a[i];
	cout<<"The polynomail value is "<<polynomail(a,n,x,n)<<endl;
	return 0;
}
