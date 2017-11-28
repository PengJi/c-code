typedef struct {
	int data;
	PBTNode *lchild;
	PBTNode *rchild;
	PBTNode *parent;
} PBTNode,PBitree; //��˫��ָ����Ķ������������
void Inorder_Nonrecursive(PBitree T){
	//����ջ�ǵݹ������˫��ָ��Ķ�����
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