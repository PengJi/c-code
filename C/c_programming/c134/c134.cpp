//冒泡法排序
#include <stdio.h>

int main(){
	int i,j,t;
	int a[10];
	printf("请输入10个整数\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<9;i++){
		for(j=0;j<9-i;j++){
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("the sorted numbers:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}