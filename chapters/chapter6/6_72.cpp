void PrintCTree(int e,int i=0){
	//���������ʽ��ӡ�������Ԫ�أ�iΪ������ڲ��
	for(j=1;j<=i;j++)
		cout<<" ";
	cout<<T.nodes[e].data<<endl;
	for(p=T.nodes[e].firstchild;p;p=p->next)
		PrintCTree(p->child,i+1);
}