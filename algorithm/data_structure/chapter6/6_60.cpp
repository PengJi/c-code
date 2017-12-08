int LeafCount_CSTree(CSTree T){
	//求孩子兄弟链表表示的树T 的叶子数目
	if(!T->firstchild) 
		return 1;
	else{
		count=0;
		for(child=T->firstchild;child;child=child->nextsib)
			count+=LeafCount_CSTree(child);
		return count;
	}
}