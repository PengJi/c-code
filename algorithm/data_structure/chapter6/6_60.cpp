int LeafCount_CSTree(CSTree T){
	//�����ֵ������ʾ����T ��Ҷ����Ŀ
	if(!T->firstchild) 
		return 1;
	else{
		count=0;
		for(child=T->firstchild;child;child=child->nextsib)
			count+=LeafCount_CSTree(child);
		return count;
	}
}