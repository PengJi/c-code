void PringBiTree(BiTree T,int i){
	//按树状打印输出二叉树的元素，i表示结点所在的层次
	if(T->rchild)
		PrintBiTree(T->rchild,i+1);
	for(j=1;j<=i;j++)
		cout<<" ";
	cout<<T->data<<endl;
	if(T->lchild)
		PrintBiTree(T->rchild,i+1);
}