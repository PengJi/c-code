void Free_Fdlf(char *addr,int n){
	//对应上一题，释放算法
	while(Gettop(S,b) && b,start<addr){
		Pop(S,b);
		Push(T,b);
	}
	if(Gettop(T,b) && (b.start+b.size == addr)){
		Pop(T,b);
		addr = b.start;
		n += b.size;
	}
	if(Gettop(S,b) && (addr+n == b.start)){
		Pop(S,b);
		n+=b.size;
	}
	Push(S,{addr,n});
	while(!StackEmpty(T)){
		Pop(T,b);
		Push(S,b);
	}
}