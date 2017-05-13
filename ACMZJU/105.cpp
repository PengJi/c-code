//4.1 quicksum
#include <iostream>

using namespace std;

int main(){
	char ch;
	int sum=0;
	int i=1;
	while(cin.get(ch)){
		if(ch=='#')
			break;
		if(ch != '\n'){
			if(ch != ' ')
				sum = sum+i*(ch-64);
			i++;
		}
		if(ch == '\n'){
			cout<<sum<<endl;
			sum=0;
			i=1;
		}

	}

	return 0;
}
