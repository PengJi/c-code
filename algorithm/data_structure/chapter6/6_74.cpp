void PrintGlistCSTree(CSTree T){
	//���������ʽ��������ֵ������ʾ����
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