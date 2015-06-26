#include <iostream>

using namespace std;

//判断是否为素数
bool isPrime(int m){
	int n=m/2;
	if(m==2){
		return false;
	}
	for(int i=2;i<=n;i++){
		if(m%i==0)
			return false;
	}
	return true;
}

//判断五位以内是否对称
bool isSym(int n){
	if(n<12 && n!=10){
		return true;
	}
	//三位数
	if(n>100 && n<1000 && n/100 == n%10)
		return true;
	//四位对称数不可能为素数
	//五位数
	if(n>10000 && n<100000 && n/1000 == n%10*10+n/10%10)
		return true;
		
	return false;
}

int main(){
	//cout<<isPrime(2)<<endl;
	int m;
	while(cin>>m)
		cout<<(isPrime(m) && isSym(m) ? "Yes" : "No")<<endl;

	return 0;
}