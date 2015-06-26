int allBracketsTest(char *str){
	//判别表达式中三种括号是否匹配
	InitStack(s);
	for(p=str;*p;p++){
		if(*p=='(' || *p=='[' || *p=='{')
			push(s,*p);
		else if(*p==')' || *p==']' || *p=='}'){
			if(StackEmpty(s))
				return 0;
			pop(s,c);
			if(*p==')' && c!='(')
				return 0;
			if(*p==']' && c!= '[')
				return 0;
			if(*p=='}' && c!='{')
				return 0;
		}
	}
	if(!StackEmpty(s))
		return 0;
	return 0;
}