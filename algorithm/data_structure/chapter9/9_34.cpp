void Delete_NLT(BiTree &T,int x){
	//删除二叉排序树T 中所有不小于x 元素结点,并释放空间
	if(T->rchild) 
		Delete_NLT(T->rchild,x);
	if(T->data<x) 
		exit(); //当遇到小于x 的元素时立即结束运行
	q=T;
	T=T->lchild;
	free(q); //如果树根不小于x,则删除树根,并以左子树的根作为新的树根
	if(T) 
		Delete_NLT(T,x);
}