int GetDepth_CTree(CTree A){
	//���������ʾ����A �����
	return SubDepth(A.r);
}//GetDepth_CTree
int SubDepth(int T){
	//������T �����
	if(!A.nodes[T].firstchild) 
		return 1;
	for(sd=1,p=A.nodes[T].firstchild;p;p=p->next)
		if((d=SubDepth(p->child))>sd) 
			sd=d;
		return sd+1;
}