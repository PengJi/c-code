typedef struct {
	int data;
	EBTNode *lchild;
	EBTNode *rchild;
	EBTNode *parent;
	enum {0,1,2} mark;
} EBTNode,EBitree; //有mark 域和双亲指针域的二叉树结点类型
void PostOrder_Nonrecursive(EBitree T){
	//后序遍历二叉树的非递归算法,不用栈
	p=T;
	while(p)
		switch(p->mark){
		case 0:
			p->mark=1;
			if(p->lchild) 
				p=p->lchild;
			break;
		case 1:
			p->mark=2;
			if(p->rchild) 
				p=p->rchild; 
			break;
		case 2:
			visit(p);
			p->mark=0; 
			p=p->parent;
		}
}