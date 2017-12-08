int GetDegreeCSTree(CSTree T){
	//求孩子兄弟链表表示的树T 的度
	if(!T->firstchild) 
		return 0; 
	else
	{
		degree=0;
		for(p=T->firstchild;p;p=p->nextsib)
			degree++;
		for(p=T->firstchild;p;p=p->nextsib){
			d=GetDegreeCSTree(p);
			if(d>degree) degree=d;
		}
		return degree;
	}
}