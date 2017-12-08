void PrintGlistCSTree(CSTree T){
	//按广义表形式输出孩子兄弟链表表示的树
	cout<<T->data;
	if(T->firstchild){
		cout<<"(";
		for(p=T->firstchild;p;p->nextsib){
			PrintGlistCSTree(p);
			if(p->nextsib)
				cout<<",";
		}
		cout<<")";
	}
}