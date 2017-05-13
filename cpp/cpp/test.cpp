#include <iostream>
#include <cstdio>
using namespace std;

// 求一串数字之和

int main(){
	freopen("in", "r", stdin);
	int sum = 0;

	int i;
	while(cin>>i){
		sum += i;
	}

	cout<<sum<<endl;

	return 0;
}
