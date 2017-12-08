int Is_Descendant_C(int u,int v){
	//在孩子存储结构上判断u 是否v 的子孙,是则返回1,否则返回0
	if(u==v) 
		return 1;
	else{
		if(L[v])
			if (Is_Descendant(u,L[v])) 
				return 1;
		if(R[v])
			if (Is_Descendant(u,R[v])) 
				return 1;
	}
	return 0;
}