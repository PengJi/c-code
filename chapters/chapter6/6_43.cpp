void Bitree_Revolute(Bitree T){
	//交换所有结点的左右子树
	T->lchild<->T->rchild;
	if(T->lchild) 
		Bitree_Revolute(T->lchild);
	if(T->rchild) 
		Bitree_Revolute(T->rchild); 
}