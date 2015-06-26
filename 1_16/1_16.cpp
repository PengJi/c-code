#include <iostream>
using namespace std;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	if(x>y){
		if(x>z)
			if(y>z)
				cout<<x<<" "<<y<<" "<<z<<endl;
			else
				cout<<x<<" "<<z<<" "<<y<<endl;
		else
			cout<<z<<" "<<x<<" "<<y<<endl;
	}else{
		if(y>z)
			if(x>z)
				cout<<y<<" "<<x<<" "<<z<<endl;
			else
				cout<<y<<" "<<z<<" "<<x<<endl;
		else
			cout<<z<<" "<<y<<" "<<x<<endl;

	}
}