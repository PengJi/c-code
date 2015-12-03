int getValueNiBoLan(char *str){
	//对逆波兰表达式*str求值
	p=str;
	InitStack(s);//s为操作数栈
	while(*p){
		if(*p>=48 &&*p<=57)
			push(s,*p);
		else{
			pop(s,a);
			pop(s,b);
			r=compute(a,b,*p);//计算
			push(s,r);
		}
		p++;
	}
	pop(s,r);
	return r;
}