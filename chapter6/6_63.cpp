int GetDepth_CTree(CTree A){
	//求孩子链表表示的树A 的深度
	return SubDepth(A.r);
}//GetDepth_CTree
int SubDepth(int T){
	//求子树T 的深度
	if(!A.nodes[T].firstchild) 
		return 1;
	for(sd=1,p=A.nodes[T].firstchild;p;p=p->next)
		if((d=SubDepth(p->child))>sd) 
			sd=d;
		return sd+1;
}