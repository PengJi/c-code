int NiBolanToBolan(StringType str,StringType &newStr){
	//���沨�����ʽ(ǰ׺���ʽ)strת��Ϊ�������ʽ(��׺���ʽ)
	InitStack(s);
	for(int i=1;i<=strlen(str);i++){
		r=subString(str,i,1);
		if(r>=97&&r<=122)
			push(s,r);
		else{
			if(StackEmpty(s))
				return 0;
			pop(s,a);
			if(StackEmpty(s))
				return 0;
			pop(s,b);
			StrAssign(t,Concat(r,b));
			StrAssign(c,Concat(t,a));
			push(s,c);
		}
	}
	pop(s,newStr);
	if(!StackEmpty(s))
		return 0;
	return 1;
}