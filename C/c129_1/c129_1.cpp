//���Լ������С������
#include <stdio.h>
int main(){
	int m,n,p,r;
	int tmp;
	printf("������������������");
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
	printf("���ǵ����Լ��Ϊ��%d\n",n);
	printf("���ǵ���С������Ϊ��%d\n",p/n);

	return 0;
}