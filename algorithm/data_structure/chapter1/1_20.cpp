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
	cout<<"�����������ֵx:";
	cin>>x;
	cout<<"���������ʽ�Ľ״�n:";
	cin>>n;
	if(n>N-1) exit(0);
	cout<<"���������ʽ��ϵ��a[0]--a[n]:";
	for(i=0;i<=n;i++) cin>>a[i];
	cout<<"The polynomail value is "<<polynomail(a,n,x,n)<<endl;
	return 0;
}
