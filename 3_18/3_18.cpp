int bracketTest(char *str){
	//�жϱ��ʽ�е�С�����Ƿ�ƥ��
	count=0;
	for(p=str;*p;p++){
		if(*p=='(')
			count++;
		else if(*p==')')
			count--;
		if(count<0)
			return 0;
	}
	if(count)
		return 0;
	return 1;
}