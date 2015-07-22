typedef struct xorNode{
	char data;
	struct xorNode *LRPtr;
}xorNode,*xorPoint;
typedef struct{
	xorPoint left,right;
}xorLinkedList;
int deleteList(xorLinkedList &L,int i){
	//删除异或链表的第i个结点
	p=L.left;
	pre=NULL;
	if(i==1){
		q=p->LRPtr;
		q->LRPtr=XorP(q->LRPtr,p);
		L.left=q;
		free(p);
		return 1;
	}
	j=1;
	q=p->LRPtr;
	while(++j<i&&q){
		q=XorP(p->LRPtr,pre);
		pre=p;
		p=q;
	}
	if(!q)
		return 0;
	if(L.right==q){
		p->LRPtr=XorP(p->LRPtr,q);
		L.right=p;
		free(q);
		return 1;
	}
	r=XorP(q->LRPtr,p);
	p->LRPtr=XorP(XorP(p->LRPtr,q),r);
	r->LRPtr=XorP(XorP(r->LRPtr,q),p);
	free(q);
	return 1;
}