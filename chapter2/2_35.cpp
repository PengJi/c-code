typedef struct xorNode{
	char data;
	struct xorNode *LRPtr;
}xorNode,*xorPoint;
typedef struct{
	xorPoint left,right;
}xorLinkedList;
int insertXorList(xorLinkedList &L,int i,int x){
	//���������ĵ�i�����ǰ������x
	xorPoint p;
	p=L.left;
	pre=NULL;
	r=(xorNode *) malloc(sizeof(xorNode));
	r->data=x;
	if(i==1){//λ�������
		p->LRPtr=XorR(p->LRPtr,r);
		r->LRPtr=p;
		L.left=r;
		return 1;
	}
	j=1;
	q=p->LRPtr;//λ���м�
	while(++j<i&&q){
		q=XorP(p->LRPtr,pre);
		pre=p;
		p=q;
	}
	if(!q)
		return 0;
	p->LRPtr=XorP(XorP(p->LRPtr,q),r);
	q->LRPtr=XorP(XorP(q->LRPtr,q),r);
	r->LRPtr=XorP(p,q);
	
	return 1;
}
