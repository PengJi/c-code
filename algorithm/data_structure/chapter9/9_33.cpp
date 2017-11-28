void Print_NLT(BiTree T,int x){
	//从大到小输出二叉排序树T 中所有不小于x 的元素
	if(T->rchild) 
		Print_NLT(T->rchild,x);
	if(T->data<x) 
		exit(); //当遇到小于x 的元素时立即结束运行
	printf("%d\n",T->data);
	if(T->lchild) 
		Print_NLT(T->lchild,x); //先右后左的中序遍历
}