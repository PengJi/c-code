int insertList1(LinkList &L,int i,int b){
	//在不带头结点的单链表L中的第i个结点前插入结点b
	LinkList p,q;
	p=L;
	q=(LNode *) malloc(sizeof(LNode));
	q.data=b;
	if(i==1){
		q.next=p;
		L=q;
	}else{
		while(--i>1)
			p=p->next;
		q->next=p->next;
		p->next=q;
	}
}
int insertList2(LinkList &L,int i,int b){
	//在带头结点的单链表L中的第i个结点前插入结点b
	LinkLit p,q;
	q=(LNode *) malloc(sizeof(LNode));
	q.data=b;
	p=L->next;
	while(--i>1)
		p=p->next;
	q->next=p->next;
	p->next=q;
}