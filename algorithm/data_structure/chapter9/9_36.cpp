void BSTree_Insert_Key(BiThrTree &T,int x){
	//在后继线索二叉排序树T 中插入元素x
	if(T->data<x){
		if(T->rtag) {
			p=T->rchild;
			q=(BiThrNode*)malloc(sizeof(BiThrNode));
			q->data=x;
			T->rchild=q;T->rtag=0;
			q->rtag=1;q->rchild=p;
		}
		else 
			BSTree_Insert_Key(T->rchild,x);
	}
	else if(T->data>x){ //插入到左子树中
		if(!T->lchild){ //T 没有左子树时,作为左孩子插入
			q=(BiThrNode*)malloc(sizeof(BiThrNode));
			q->data=x;
			T->lchild=q;
			q->rtag=1;q->rchild=T; //修改自身的线索
		}
		else 
			BSTree_Insert_Key(T->lchild,x);//T 有左子树时,插入左子树中
	}
}