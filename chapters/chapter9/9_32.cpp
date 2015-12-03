int last=0;
void MaxLT_MinGT(BiTree T,int x){
	//找到二叉排序树T 中小于x 的最大元素和大于x 的最小元素
	if(T->lchild) 
		MaxLT_MinGT(T->lchild,x);
	if(last<x&&T->data>=x) //找到了小于x 的最大元素
		printf("a=%d\n",last);
	if(last<=x&&T->data>x) //找到了大于x 的最小元素
		printf("b=%d\n",T->data);
	last=T->data;
	if(T->rchild) 
		MaxLT_MinGT(T->rchild,x);
}