#include <iostream>
#include <string>

//4.2 IBM Minus One

using namespace std;

int main(){
	int n;
	string s;
	int j=0;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		cout<<"string #"<<i+1<<endl;
		while(s[j] != '\0'){
			cout<<(s[j] != 'z'?char(s[j]+1):'A');
			j++;
		}
		j=0;
		cout<<endl;
		cout<<endl;
	}

	return 0;
}
