void PrintCSTree(CSTree T,int i){
	//���������ʽ��ӡ�������Ԫ�أ�i��ʾ������ڲ��
	for(j=1;j<=i;j++)
		cout<<" ";
	cout<<T->data<<endl;
	for(p=T->firstchild;p;p=p->nextsib)
		PrintCSTree(p,i+1);
}