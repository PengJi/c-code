//12!Åä¶Ô

#include <iostream>
#include <set>
using namespace std;

int main(){
	int num=0;
	int f12=479001600;//=12!

	multiset<unsigned int> s;
	int n;

	while(cin>>n){
		if(f12%n==0)
		{
			multiset<unsigned int>::iterator it=s.find(f12/n);
			if(it!=s.end()){
				num++;
				s.erase(it);
			}else{
				s.insert(n);
			}
		}
		cout<<num<<endl;
	}

	cout<<num<<endl;
	return 0;
}