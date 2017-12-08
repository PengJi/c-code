typedef struct{
	char *start;
	int size;
}fmblock;
char *Malloc_Fdlf(int n){
	//内存分配算法：最后分配最先释放
	while(Gettop(S,b) && b.size<n){
		Pop(S,b);//S为栈
		Push(T,b);//T为栈
	}
	if(StackEmpty(S))
		return NULL;
	Pop(S,b);
	b.size -= n;
	if(b.size)
		Push(S,{b.start+n,b.size});
	while(!StackEmpty(T)){
		Pop(T,a);
		Push(S,a);
	}
	return b.start;
}