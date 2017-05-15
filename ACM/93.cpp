//01¥Æ≈≈–Ú
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct Comp{
	bool operator()(const string &s1,const string &s2){
		if(s1.length() != s2.length()) 
			return s1.length()<s2.length();
		int c1=count(s1.begin(),s1.end(),'1');
		int c2=count(s2.begin(),s2.end(),'1');
		return (c1 != c2?c1<c2:s1<s2);
	}
};

int main(){
	multiset<string,Comp> ms;
	string s;
	//while(cin>>s&&!cin){
	while(cin>>s){
		if(s =="#")
			break;
		ms.insert(s);
	}
	cout<<"end"<<endl;
	for(multiset<string,Comp>::iterator it = ms.begin();it != ms.end();it++)
		cout<<*it<<endl;

	return 0;
}