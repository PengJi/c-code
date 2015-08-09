void BSTree_Split(BiTree &T,BiTree &A,BiTree &B,int x){
	//把二叉排序树T 分裂为两棵二叉排序树A 和B,其中A 的元素全部小于等于x,B 的元素全部大于x
	if(T->lchild)
		BSTree_Split(T->lchild,A,B,x);
	if(T->rchild)
		BSTree_Split(T->rchild,A,B,x); //分裂左右子树
	if(T->data<=x) 
		Insert_Node(A,T);
	else 
		Insert_Node(B,T); //将元素结点插入合适的树中
}
void Insert_Node(Bitree &T,BTNode *S){
	//把树结点S 插入到T 的合适位置上
	if(!T) T=S;
	else if(S->data>T->data){
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
	S->lchild=NULL;
	S->rchild=NULL;
}