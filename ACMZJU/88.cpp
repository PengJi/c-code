//十进制转化为二进制

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while (cin>>n){
		if(n==0){
			cout<<"          0-->0\n";
			continue;
		}
		string s="";
		for(int a=n;a;a=a/2){
			s=s+(a%2?'1':'0');
		}
		std::reverse(s.begin(),s.end());
		const char *sss=s.c_str();
		cout.width(11);
		cout<<n<<(n<0?"-->-":"-->")<<sss<<"\n";

	}

	return 0;
}

