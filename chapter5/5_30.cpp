int GListDeph(GList L){
	//求广义表深度的递归算法
	if(!L->tag)
		return 0;
	else if(!L)
		return 1;
	m=GListDeph(L->ptr.hp)+1;
	n=GListDeph(L->ptr.tp);
	return m>n?m:n;
}