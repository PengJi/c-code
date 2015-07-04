void GListReverse(GList A){
	//递归逆转广义表
	GLNode *ptr[MaxSiexe];
	if(A->tag&&A->ptr.tp){
		for(i=0,p=A;p;p=p->ptr.tp,i++){
			if(p->ptr.hp)
				GList_Reverse(p->ptr.hp);
			ptr[i]=p->ptr.hp;
		}
		for(p->A;p;p=p->ptr.tp)
			p->ptr.ho=ptr[--i];
	}
}