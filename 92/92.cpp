#include <iostream>

using namespace std;

//�ж��Ƿ�Ϊ����
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

//�ж���λ�����Ƿ�Գ�
bool isSym(int n){
	if(n<12 && n!=10){
		return true;
	}
	//��λ��
	if(n>100 && n<1000 && n/100 == n%10)
		return true;
	//��λ�Գ���������Ϊ����
	//��λ��
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