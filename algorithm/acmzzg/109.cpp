#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string s;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		c=s[0];//保存值
		int tmp=0;
		for(int j=0;j<s.size();j++){
			if(s[j]==c){//值相同
				tmp++;
				//最后一个元素
				if(j==s.size()-1){
					if(tmp==1)
						cout<<c;
					else 
						cout<<tmp<<c;
				}
			}else{//值不同
				if(tmp==1)
					cout<<c;
				else 
					cout<<tmp<<c;
				c=s[j];
				tmp=1;
				//最后一个元素
				if(j==s.size()-1){
					if(tmp==1)
						cout<<c;
					else 
						cout<<tmp<<c;

				}
			}
		}
		cout<<endl;
		s="";
	}

	return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string s,t;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		t=s[0];//保存值
		int tmp=0;
		for(int j=0;j<s.size();j++){
			if(s[j]==t[0]){//值相同
				tmp++;
				//最后一个元素
				if(j==s.size()-1){
					if(tmp==1)
						cout<<t[0];
					else 
						cout<<tmp<<t[0];
				}
			}else{//值不同
				if(tmp==1)
					cout<<t[0];
				else 
					cout<<tmp<<t[0];
				t=s[j];
				tmp=1;
				//最后一个元素
				if(j==s.size()-1){
					if(tmp==1)
						cout<<t[0];
					else 
						cout<<tmp<<t[0];

				}
			}
		}
		cout<<endl;
		s="";
	}

	return 0;
}
*/