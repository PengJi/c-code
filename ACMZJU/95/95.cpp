//≈≈¡–∂‘≥∆¥Æ

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

/*
bool Comp(const string &s1,const string &s2){
	return (s1.length() != s2.length())? s1.length()<s2.length():s1<s2;
}
*/

struct Comp{
	bool operator()(const string &s1,const string &s2){
		return (s1.length() != s2.length())? s1.length()<s2.length():s1<s2;
	}
};

int main(){
	string s1,s2;
	multiset<string,Comp> ms;
	while(cin>>s1){
		if(s1 == "#"){
			break;
		}
		s2=s1;
		reverse(s1.begin(),s1.end());
		if(s1==s2)
			ms.insert(s1);
	}
	for(multiset<string,Comp>::iterator it=ms.begin();it != ms.end();it++){
		cout<<*it<<endl;
	}

	return 0;
}