typedef struct{
	ElemType data;
	DNode *prier,*next;
}DNode,*DLinkList;
int DListReform(DLinkList &L){
	//将带头结点的双循环链表结点为下标为1,2,3,...,n,重排为1,3,5,...,n,4,2
	//要求时间为n
	p=L->next;
	if(!p)
		return 0;
	while(p->next!=L && p->next->next!=L){
		p->next=p->next->next;
		p=p->next;
	}
	if(p->next==L)
		p->next=L->prier->prier;
	else
		p->next=L->prier;
	p=p->next;
	while(p->prier>prier!=L){
		p->next=p->prier->prier;
		p=p->next;
	}
	p->next=L;
	for(p=L;p->next!=L;p=p->next)
		p->next->prier=p;
	L->prier=p;
}