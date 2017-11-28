int Get_Sub_Depth(Bitree T,int x){
	//求二叉树中以值为x 的结点为根的子树深度
	if(T->data==x){
		printf("%d\n",Get_Depth(T));
		exit 1;
	}
	else{
		if(T->lchild) 
			Get_Sub_Depth(T->lchild,x);
		if(T->rchild) 
			Get_Sub_Depth(T->rchild,x);
	}
}
int Get_Depth(Bitree T)
	//求子树深度的递归算法
	if(!T) 
		return 0;
	else{
		m=Get_Depth(T->lchild);
		n=Get_Depth(T->rchild);
		return (m>n?m:n)+1;
	}
}