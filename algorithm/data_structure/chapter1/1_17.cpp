#include <iostream>
#include <cmath>
using namespace std;
int fibonacci(int k,int m)
{
	if(m<0)
		exit(0);
	if(m>=0&&m<k-1)
		return 0;
	if(m==k-1)
		return 1;
	int x,*p;
	p=new int[m+1];
	int i,j;
	for(i=0;i<k+1;i++){
		if(i<k-1) p[i]=0;
		else p[i]=1;
	}

	for(i=k+1;i<m+1;i++){
		x=p[0];
		for(j=0;j<k;j++) 
			p[j]=p[j+1];
		p[k]=2*p[k-1]-x;
	}
	return p[k];
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<fibonacci(a,b)<<endl;
	
	return 0;
}