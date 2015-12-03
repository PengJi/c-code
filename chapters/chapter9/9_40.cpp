typedef struct {
	int data;
	int bf;
	int lsize; 
	BlcNode *lchild,*rchild;
} BlcNode,*BlcTree; 
BTNode *Locate_BlcTree(BlcTree T,int k){
	//在含lsize 域的平衡二叉排序树T 中确定第k 小的结点指针
	if(!T) 
		return NULL; 
	if(T->lsize==k)
		return T; 
	else if(T->lsize>k)
		return Locate_BlcTree(T->lchild,k); //在左子树中寻找
	else 
		return Locate_BlcTree(T->rchild,k-T->lsize); //在右子树中寻找,注意要修改k 的值
}