BTNode *PreOrder_Next(BTNode *p){
	//在先序后继线索二叉树中查找结点p 的先序后继,并返回指针
	if(p->lchild) 
		return p->lchild;
	else 
		return p->rchild;
}