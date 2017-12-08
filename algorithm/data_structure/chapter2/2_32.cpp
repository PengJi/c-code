typedef struct{
	ElemType data;
	LNode *next;
	LNode *pre;
}LNode,*LinkList;
int change2dul(LinkList &L){
	//将循环单链表改为双向循环链表
	LinkList p;
	p=L;
	if(!p)
		return 0;
	while(!p->next->pre){
		p->next->pre=p;
		p->next;
	}
	return 1;
}