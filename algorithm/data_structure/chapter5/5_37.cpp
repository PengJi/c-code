void GListDelElem(GList &A,int x){
	//从广义表A中删除所有值为x的原子
	if(A&&A->ptr.hp){
		if(A->ptr.hp->tag)
			GListDelElem(A->ptr.hp,x);
		else if(!A->ptr.hp->tag&&A->ptr.hp->atom==x){
			q=A;
			A=A->ptr.tp;
			free(q);
			GListDelElem(A,x);
		}
	}
	if(A&&A->ptr.tp)
		GListDelElem(A->ptr.tp,x);
}