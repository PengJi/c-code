#include <stdio.h>
int main(){
	int num[4],max,flag,num_max[4];
	printf("请输入4个整数：\n");
	scanf("%d%d%d%d",&num[0],&num[1],&num[2],&num[3]);
	max=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(num[j]>max){
				max=num[j];
				flag=j;
			}
		}
		num_max[i]=max;
		num[flag]=0;
		max=0;
	}
	printf("从小到大为：\n");
	for(int k=3;k>=0;k--)
		printf("%d\n",num_max[k]);

	return 0;
}
