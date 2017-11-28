typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int listInterset(LinkList &A,LinkList &B){
	//使用链表实现上面算法
	LinkList p,q,r;
	if(!A || !B)
		return 0;
	p=B->next;
	q=B->next;
	r=A;
	while(p&&q){
		if(p->data<q->data)
			p=p->next;
		else if(p->data>q->data)
			q=q->next;
		else
			if(p->data != r->data){
				r=r->next;
				r->data=p->data;
				p=p->next;
				q=q->next;
			}else{
				q=p->next;
				q=q->next;
			}
	}
}