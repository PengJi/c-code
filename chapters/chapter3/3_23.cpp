int NiBoLanToBoLan(char *str,char *new){
	//���沨�����ʽstrת��Ϊ�������ʽnew
	p=str;
	InitStack(s);
	while(*p){
		if(*p>=97 && *p<=122)//����ĸ
			push(s,*p);
		else{
			if(StackEmpty(s))
				return 0;
			pop(s,a);
			if(StackEmpty(s))
				return 0;
			pop(s,b);
			c=link(link(*p,b),a);//��ĸ����
			push(s,c);
		}
		p++;
	}
	pop(s,*new);
	new++;
	if(!StackEmpty(s))
		return 0;
}