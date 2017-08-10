#include <iostream>
#include <string>
#include <vector>
using namespace std;

//反转的数字相加

int main(){
	string sa,sb,st;
	vector<int> v;
	int a,b,sum;
	int p=0;//进位标志
	int u=0;//输出标志
	cin>>sa;
	while(cin>>sa>>sb){
		if(sa.size()<sb.size()){
			st=sa;
			sa=sb;
			sb=st;
		}
		for(int i=0;i<sa.size();i++){
			if(sa[i] == '0') a=0;
			else if(sa[i] == '1') a=1;
			else if(sa[i] == '2') a=2;
			else if(sa[i] == '3') a=3;
			else if(sa[i] == '4') a=4;
			else if(sa[i] == '5') a=5;
			else if(sa[i] == '6') a=6;
			else if(sa[i] == '7') a=7;
			else if(sa[i] == '8') a=8;
			else if(sa[i] == '9') a=9;
			if(i>=sb.size()) b=0;
			else if(sb[i] == '1') b=1;
			else if(sb[i] == '2') b=2;
			else if(sb[i] == '3') b=3;
			else if(sb[i] == '4') b=4;
			else if(sb[i] == '5') b=5;
			else if(sb[i] == '6') b=6;
			else if(sb[i] == '7') b=7;
			else if(sb[i] == '8') b=8;
			else if(sb[i] == '9') b=9;

			sum=a+b+p;
			p=sum/10;//本次的进位
			v.push_back(sum%10);//各位

		}
		if(p==1) v.push_back(1);
		while(1){
			vector<int>::iterator it=v.end()-1;
			if(*it==0) v.erase(it);
			else break;
		}
		for(int j=0;j<v.size();j++){
			if(u==0 && v[j] != 0) u=1;
			if(u==1) cout<<v[j];
		}
		cout<<endl;
		v.clear();
		u=0;
		p=0;
	}

	return 0;
}