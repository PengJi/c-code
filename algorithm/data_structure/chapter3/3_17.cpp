int isReverse(){
	//�ж�������ַ�����'&'ǰ��'&'�󲿷ֵ��ַ����Ƿ��档
	InitStack(s);
	while((e=getchar())!='&'){
		if(e=='@')
			return 0;
		push(s,e);
	}
	while((e=getchar())1='@'){
		if(StackEmpty(s))
			return 0;
		pop(s,c);
		if(e!=c)
			return 0
	}
	if(!StackEmpty(s))
		return 0;
	return 1;
}