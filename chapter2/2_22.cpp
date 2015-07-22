typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
LinkList ReverseList(LinkList &L){
	//将带头结点的单链表就地逆置
	//采用头插法，将链表的头结点摘下，然后再依次把链表的各个结点插入头结点的后面
	LinkList r;
	p=L->next;
	L->next=NULL;
	while(p!=NULL){
		r=p->next;
		p->next=L->next;
		L->next=p;
		p=r;
	}
	return L;
}