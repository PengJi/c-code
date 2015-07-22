int bracketTest(char *str){
	//判断表达式中的小括号是否匹配
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