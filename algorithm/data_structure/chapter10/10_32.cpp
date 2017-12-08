typedef enum {RED,WHITE,BLUE} color; 
void Flag_Arrange(color a[ ],int n){
	//把由三种颜色组成的序列重排为按照红,白,蓝的顺序排列
	int i=0;
	int j=0;
	int k=n-1;
	while(j<=k)
		switch(a[j]){
			case RED:
				a[i]<->a[j];
				i++;
				j++;
				break;
			case WHITE:
				j++;
				break;
			case BLUE:
				a[j]<->a[k];
				k--; 
		}
}