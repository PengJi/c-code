int LeafCount_BiTree(Bitree T){
	//���������Ҷ�ӽ�����Ŀ
	if(!T) return 0; 
	else if(!T->lchild&&!T->rchild) 
		return 1; //Ҷ�ӽ��
	else 
		return Leaf_Count(T->lchild)+Leaf_Count(T->rchild);
}