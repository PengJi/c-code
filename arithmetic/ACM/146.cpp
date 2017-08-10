#include <iostream>
#include <string>
using namespace std;

//漂亮的草坪

int main(){
	int p[10][10];
	int n,m;
	int i,j,k;
	int flag=1;
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		flag=1;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>p[i][j];
				if(p[i][j] =0) flag=0;//修剪过
			}
		}
		//第一种情况：全是1
		if(flag==1){
			cout<<"No"<<endl;
			continue;
		}
		//第二种情况：0不相邻
		//判断第0行
		for(k=1;k<m;k++){
			if(p[0][k]==0 && p[0][k-1] ==0){
				cout<<"No"<<endl;
				goto RL;
			}
		}
		//判断第1~N-1行
		for(i=1;i<n;i++){
			for(int j=0;j<m;j++){
				if(p[i][j]==0 && p[i-1][j]==0){
					cout<<"No"<<endl;
					goto RL;
				}
				if(j != 0){
					if(p[i][j] == 0 && p[i][j-1] == 0){
						cout<<"No"<<endl;
						goto RL;
					}
				}
			}
		}
		cout<<"Yes"<<endl;
		continue;
RL:
		continue;
	}

	return 0;
}