//string对象与字符数组相互操作
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	char ss[100];

	scanf("%s",&ss);
	s=ss;

	printf(s.c_str());
	cout<<endl;

	printf("%s",ss);
	cout<<endl;

	cout<<s<<endl;
	cout<<ss<<endl;

	return 0;
}
