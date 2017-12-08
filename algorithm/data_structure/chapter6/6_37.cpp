void PreOrder_Nonrecursive(Bitree T){
	//先序遍历二叉树的非递归算法
	InitStack(S);
	Push(S,T);
	while(!StackEmpty(S)){
		while(Gettop(S,p)&&p){
			visit(p->data);
			push(S,p->lchild);
		}
		pop(S,p);
		if(!StackEmpty(S)){
			pop(S,p);
			push(S,p->rchild);
		}
	}
}