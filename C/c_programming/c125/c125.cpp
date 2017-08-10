#include <stdio.h>
int main(){
	int num[40];
	num[0]=1;
	num[1]=1;
	for(int i=2;i<40;i++){
		num[i]=num[i-1]+num[i-2];
	}
	printf("前40个数为：\n");
	for(int j=0;j<40;j++){
		printf("%d ",num[j]);
		if(j%5==0)
			printf("\n");
	}

	return 0;
}