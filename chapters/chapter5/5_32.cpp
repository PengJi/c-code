int GListEqual(GList A,GList B){
	//�ж����������A��B�Ƿ����
	if(!A&&!B)
		return 1;
	if(!A->tag&&!B->tag&&A->atom==B->atom)
		return 1;
	if(A->tag&&B->tag)
		if(GListEqual(A->ptr.hp,B->ptr.hp)&&GListEqual(A->ptr.tp,B->ptr.tp))
			return 1;
	return 0;
}