typedef enum {RED,WHITE,BLUE} color; 
void Flag_Arrange(color a[ ],int n){
	//����������ɫ��ɵ���������Ϊ���պ�,��,����˳������
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