//最大公约数和最小公倍数
#include <stdio.h>
int main(){
	int m,n,p,r;
	int tmp;
	printf("请输入两个正整数：");
	scanf("%d,%d",&n,&m);
	if(n<m){
		tmp=n;
		n=m;
		m=tmp;
	}
	p=n*m;
	while(m!=0){
		r=n%m;
		n=m;
		m=r;
	}
	printf("它们的最大公约数为：%d\n",n);
	printf("它们的最小公倍数为：%d\n",p/n);

	return 0;
}