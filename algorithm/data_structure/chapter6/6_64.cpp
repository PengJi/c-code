int GetDepth_PTree(PTree T){
	//��˫�ױ��ʾ����T �����
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