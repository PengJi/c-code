int getValueNiBoLan(char *str){
	//���沨�����ʽ*str��ֵ
	p=str;
	InitStack(s);//sΪ������ջ
	while(*p){
		if(*p>=48 &&*p<=57)
			push(s,*p);
		else{
			pop(s,a);
			pop(s,b);
			r=compute(a,b,*p);//����
			push(s,r);
		}
		p++;
	}
	pop(s,r);
	return r;
}