int GetDepthCSTree(CSTree T){
	//求孩子兄弟链表表示的树T 的深度
	if(!T) 
		return 0;
	else{
		for(maxd=0,p=T->firstchild;p;p=p->nextsib)
			if((d=GetDepthCSTree(p))>maxd) 
				maxd=d;
			return maxd+1;
	}
}