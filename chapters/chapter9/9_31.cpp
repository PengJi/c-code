int last=0,flag=1;
int Is_BSTree(Bitree T){
	//判断二叉树T 是否二叉排序树,是则返回1,否则返回0
	if(T->lchild&&flag) 
		Is_BSTree(T->lchild);
	if(T->data<last)
		flag=0; //与其中序前驱相比较
	last=T->data;
	if(T->rchild&&flag) 
		Is_BSTree(T->rchild);
	return flag;
}