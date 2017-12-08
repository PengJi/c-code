int LeafCount_BiTree(Bitree T){
	//求二叉树中叶子结点的数目
	if(!T) return 0; 
	else if(!T->lchild&&!T->rchild) 
		return 1; //叶子结点
	else 
		return Leaf_Count(T->lchild)+Leaf_Count(T->rchild);
}