typedef struct{
	ElemType *base[2];
	ElemType *top[2];
}BDStacktype; //˫��ջ����
int Init_Stack(BDStacktype &tws,int m){
	//��ʼ��һ����СΪm ��˫��ջtws
	tws.base[0]=(Elemtype*)malloc(sizeof(Elemtype));
	tws.base[1]=tws.base[0]+m;
	tws.top[0]=tws.base[0];
	tws.top[1]=tws.base[1];
	return 1;
}
int push(BDStacktype &tws,int i,Elemtype x){
	//x ��ջ,i=0 ��ʾ�Ͷ�ջ,i=1 ��ʾ�߶�ջ
	if(tws.top[0]>tws.top[1]) 
		return 0; 
	if(i==0) 
		*tws.top[0]++=x;
	else if(i==1) 
		*tws.top[1]--=x;
	else 
		return 0;
	return 1;
}
int pop(BDStacktype &tws,int i,Elemtype &x){
	//x ��ջ,i=0 ��ʾ�Ͷ�ջ,i=1 ��ʾ�߶�ջ
	if(i==0){
	if(tws.top[0]==tws.base[0]) 
		return 0;
		x=*--tws.top[0];
	}
	else if(i==1){
		if(tws.top[1]==tws.base[1]) 
			return 0;
		x=*++tws.top[1];
	}
	else 
		return 0;
	return 1;
}