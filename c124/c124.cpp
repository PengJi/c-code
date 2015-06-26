#include <stdio.h>
#include <math.h>
int main(){
	float pai,num=0,m=1,n=1.0;
	int sign=1;
	while(fabs(m)>1e-6){
		num=num+m;
		n=n+2;
		sign=-sign;
		m=sign/n;
	}
	pai=num*4;
	printf("pi=%10.6f\n",pai);

	return 0;
}

/*
#include <stdio.h>
#include <math.h>
void main(){
	int s;
	float n,t,pi;
	t=1;pi=0;n=1.0;s=1;
	while(fabs(t)>1e-6){
		pi=pi+t;
		n=n+2;
		s=-s;
		t=s/n;
	}
	pi=pi*4;
	printf("pi=%10.6f\n",pi);
}
*/