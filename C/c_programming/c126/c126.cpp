//判断是否为素数
#include <stdio.h>
#include <math.h>
int main(){
	int m;
	int flag=1;
	scanf("%d",&m);

	for(int i=2;i<=sqrt(m);i++){
		if(m%i == 0){
			flag=0;
			break;
		}
	}

	if(flag)
		printf("%d是素数\n",m);
	else
		printf("%d不是素数\n",m);

	return 0;
}