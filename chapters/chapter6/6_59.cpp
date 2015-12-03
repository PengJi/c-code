void Print_CSTree(CSTree T){
	//输出孩子兄弟链表表示的树T的各边
	for(child=T->firstchild;child;child=child->nextsib){
		printf("(%c,%c),",T->data,child->data);
		Print_CSTree(child);
	}
}