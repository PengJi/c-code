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
		c=s[0];//���
		int tmp=0;
		for(int j=0;j<s.size();j++){
			if(c==s[j]){
				tmp++;
				//���һ��ֱ�����
				if(j==s.size()-1){
					printf("%d%c",tmp,c);
				}
			}else{
				printf("%d%c",tmp,c);
				c=s[j];
				tmp=1;
				//���һ��ֱ�����
				if(j==s.size()-1)
					printf("%d%c",tmp,c);
			}
		}
		printf("\n");
		s="";
	}

	return 0;
}