int GListEqual(GList A,GList B){
	//判断两个广义表A和B是否相等
	if(!A&&!B)
		return 1;
	if(!A->tag&&!B->tag&&A->atom==B->atom)
		return 1;
	if(A->tag&&B->tag)
		if(GListEqual(A->ptr.hp,B->ptr.hp)&&GListEqual(A->ptr.tp,B->ptr.tp))
			return 1;
	return 0;
}