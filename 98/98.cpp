//按1的个数排序
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool Comp(const string &s1,const string &s2){
	int c1 = count(s1.begin(),s1.end(),'1');
	int c2 = count(s2.begin(),s2.end(),'1');
	return (c1!=c2)?c1<c2:c1<c2;//如果1个数相同，则按出现顺序排序
}

int main(){
	string s;
	vector<string> vs;
	while(cin>>s){
		if(s=="#"){
			break;
		}
		vs.push_back(s);
	}
	sort(vs.begin(),vs.end(),Comp);
	for(vector<string>::iterator it = vs.begin();it!=vs.end();it++)
		cout<<*it<<endl;

	return 0;
}