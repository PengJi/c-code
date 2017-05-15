#include <iostream>
#include <string>
using namespace std;

int main(){
	float a,b;
	cin>>a;
	while(cin>>b){
		if(b==999){
			printf("End of Output\n");
			break;
		}
		printf("%.2f\n",b-a);
		/*
		cout.precision(2);
		cout<<fixed<<b-a;
		*/
		a=b;
	}

	return 0;
}