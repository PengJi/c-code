int GetDepth_PTree(PTree T){
	//求双亲表表示的树T 的深度
	maxdep=0;
	for(i=0;i<T.n;i++)
	{
		dep=0;
		for(j=i;j>=0;j=T.nodes[j].parent) 
			dep++;
		if(dep>maxdep) 
			maxdep=dep;
	}
	return maxdep;
}