#include <iostream>
#include <string>
using namespace std;

int main(){
	string s,ss;
	char ch[81];
	cin.getline(ch,81);
	cin.getline(ch,81);
	int f=1;
	while(cin.getline(ch,81)){
		s=ch;
		if(s.find(' ') == 4294967295 && f!=1)
		{
			cin.getline(ch,81);
			cout<<endl;
		}
		else f=0;
		if(s.find(' ' ) != 4294967295 ){
			for(unsigned int i=0;i<s.size();i++){
				if(s[i] != ' ')
					ss=s[i]+ss;
				else
				{
					cout<<ss<<" ";
					ss="";
				}
			}
			cout<<ss<<endl;
			ss="";
		}
	}

	return 0;
}