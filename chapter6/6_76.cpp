void PrintGListCTree(CTree T,int i){
	//按广义表形式输出孩子链表表示的树
	cout<<T.nodes[i].data;
	if(T.nodes[i].firstchild){
		cout<<"(";
		for(p=T->firstchild;p;p=p->nextsib){
			PrintGlistCTree(T,p->child);
			if(p->nextsib)
				cout<<",";
		}
		cout<<")";
	}
}