#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string s;
	char ss[80];
	int n=0;
	while(cin.getline(ss,80)){
		if(n==0) n=1;
		else{
			s=ss;
			reverse(s.begin(),s.end());
			cout<<s<<endl;
		}

	}
	return 0;
}