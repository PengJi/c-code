typedef struct {
	int data;
	PBTNode *lchild;
	PBTNode *rchild;
	PBTNode *parent;
} PBTNode,PBitree; //有双亲指针域的二叉树结点类型
void Inorder_Nonrecursive(PBitree T){
	//不设栈非递归遍历有双亲指针的二叉树
	p=T;
	while(p->lchild) 
		p=p->lchild;
	while(p){
		visit(p);
		if(p->rchild){
			p=p->rchild;
			while(p->lchild) 
				p=p->lchild; 
		}else if(p->parent->lchild==p) 
			p=p->parent; 
		else{
			p=p->parent;
			while(p->parent&&p->parent->rchild==p) p=p->parent;
			p=p->parent;
		}
	}
}