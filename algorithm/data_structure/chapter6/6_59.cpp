void Print_CSTree(CSTree T){
	//��������ֵ������ʾ����T�ĸ���
	for(child=T->firstchild;child;child=child->nextsib){
		printf("(%c,%c),",T->data,child->data);
		Print_CSTree(child);
	}
}