void PrintGListCTree(CTree T,int i){
	//���������ʽ������������ʾ����
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