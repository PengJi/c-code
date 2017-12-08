typedef struct {
	int data;
	EBTNode *lchild;
	EBTNode *rchild;
	EBTNode *parent;
	enum {0,1,2} mark;
} EBTNode,EBitree; //��mark ���˫��ָ����Ķ������������
void PostOrder_Nonrecursive(EBitree T){
	//��������������ķǵݹ��㷨,����ջ
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