void GListReverse(GList A){
	//�ݹ���ת�����
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