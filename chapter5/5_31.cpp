void GListCopy(GList A,GList &B){
	//���ƹ����ĵݹ��㷨
	if(!A->tag){
		B->tag=0;
		B->atom=A->atom;
	}else{
		B->tag=1;
		if(A->ptr.hp){
			B->ptr.hp=malloc(sizeof(GLNode));
			GListCopy(A->ptr.hp,B->ptr.hp);
		}
		if(A->ptr.tp){
			B->ptr.tp=malloc(sizeof(GLNode));
			GListCopy(A->ptr.tp,B->ptr.tp);
		}
	}
}