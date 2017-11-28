void BSTree_Merge(BiTree &T,BiTree &S){
	//把二叉排序树S 合并到T 中
	if(S->lchild) 
		BSTree_Merge(T,S->lchild);
	if(S->rchild) 
		BSTree_Merge(T,S->rchild); //合并子树
	Insert_Key(T,S); //插入元素
}
void Insert_Node(Bitree &T,BTNode *S){
	//把树结点S 插入到T 的合适位置上
	if(S->data>T->data){
		if(!T->rchild) 
			T->rchild=S;
		else 
			Insert_Node(T->rchild,S);
	}
	else if(S->data<T->data){
		if(!T->lchild)
			T->lchild=S;
		else 
			Insert_Node(T->lchild,S);
	}
	S->lchild=NULL; //插入的新结点必须和原来的左右子树断绝关系
	S->rchild=NULL; //否则会导致树结构的混乱
}