int GListDeph(GList L){
	//��������ȵĵݹ��㷨
	if(!L->tag)
		return 0;
	else if(!L)
		return 1;
	m=GListDeph(L->ptr.hp)+1;
	n=GListDeph(L->ptr.tp);
	return m>n?m:n;
}