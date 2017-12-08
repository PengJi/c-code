void deleteList1(LinkList &L,int i){
	//删除不带头结点的单链表的第i个结点
	LinkList p,q;
	q=L;
	if(i==1){
		L=L->next;
		free(q);
	}
	else{
		p=L;
		while(--i>1)
			p=p->next;
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
}
void deleteList2(LinkList &L,int i){
	//删除带头结点的单链表表中的第i个结点
	LinkList p,q;
	p=L->next;
	while(--i>1)
		p=p->next;
	q=p->next;
	p->next=p->next->next;
	free(q);
}