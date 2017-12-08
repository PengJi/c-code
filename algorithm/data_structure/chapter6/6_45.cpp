void Del_Sub_x(Bitree T,int x){
	//删除所有以元素x 为根的子树
	if(T->data==x) 
		Del_Sub(T);
	else{
		if(T->lchild) 
			Del_Sub_x(T->lchild,x);
		if(T->rchild) 
			Del_Sub_x(T->rchild,x);
	}
}
void Del_Sub(Bitree T){
	//删除子树T
	if(T->lchild) 
		Del_Sub(T->lchild);
	if(T->rchild) 
		Del_Sub(T->rchild);
	free(T);
}