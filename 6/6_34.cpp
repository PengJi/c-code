int Is_Descendant_P(int u,int v){
	//在双亲存储结构上判断u 是否v 的子孙,是则返回1,否则返回0
	for(p=u;p!=v&&p;p=T[p]);
	if(p==v) 
		return 1;
	else 
		return 0;
}