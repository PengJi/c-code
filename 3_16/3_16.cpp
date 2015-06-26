void trainArrange(char *train){
	//train表示列车
	p=train;
	q=train;
	InitStack(s);
	while(*p){
		if(*p=='H')
			push(s,*p);
		else 
			*(q++)=*p;
		p++;
	}
	while(!StackEmpty(s)){
		pop(s,c);
		*(q++)=c;
	}
}