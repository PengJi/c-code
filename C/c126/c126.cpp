//�ж��Ƿ�Ϊ����
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
		printf("%d������\n",m);
	else
		printf("%d��������\n",m);

	return 0;
}