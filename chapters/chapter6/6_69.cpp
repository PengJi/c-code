void PringBiTree(BiTree T,int i){
	//����״��ӡ�����������Ԫ�أ�i��ʾ������ڵĲ��
	if(T->rchild)
		PrintBiTree(T->rchild,i+1);
	for(j=1;j<=i;j++)
		cout<<" ";
	cout<<T->data<<endl;
	if(T->lchild)
		PrintBiTree(T->rchild,i+1);
}