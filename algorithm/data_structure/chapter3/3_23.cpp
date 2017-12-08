int NiBoLanToBoLan(char *str,char *new){
	//将逆波兰表达式str转化为波兰表达式new
	p=str;
	InitStack(s);
	while(*p){
		if(*p>=97 && *p<=122)//是字母
			push(s,*p);
		else{
			if(StackEmpty(s))
				return 0;
			pop(s,a);
			if(StackEmpty(s))
				return 0;
			pop(s,b);
			c=link(link(*p,b),a);//字母连接
			push(s,c);
		}
		p++;
	}
	pop(s,*new);
	new++;
	if(!StackEmpty(s))
		return 0;
}