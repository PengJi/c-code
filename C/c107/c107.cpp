//判断某年是否闰年
#include <stdio.h>
void main(){
	int year,leap;
	scanf("%d",&year);
	if((year%4==0 && year%100 != 0)|| year%400 ==0)
		leap=1;
	else
		leap=0;
	if(leap)
		printf("%d是闰年\n",year);
	else
		printf("%d不是闰年\n",year);
}