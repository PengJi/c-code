typedef struct{
	char *start;
	int size;
}fmblock;
char *Malloc_Fdlf(int n){
	//�ڴ�����㷨�������������ͷ�
	while(Gettop(S,b) && b.size<n){
		Pop(S,b);//SΪջ
		Push(T,b);//TΪջ
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