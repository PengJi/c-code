void Bitree_Revolute(Bitree T){
	//�������н�����������
	T->lchild<->T->rchild;
	if(T->lchild) 
		Bitree_Revolute(T->lchild);
	if(T->rchild) 
		Bitree_Revolute(T->rchild); 
}