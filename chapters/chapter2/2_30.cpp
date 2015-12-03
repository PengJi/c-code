typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int deleteSameNode(LinkList &A,LinkList &B,LinkList &C){
	//同上题，存储结构变为链表，链表带头结点
	if(!A || !B || !C)
		return 0;
	if(!A->next || !B->next || !C->next)
		return 0;
	LinkList p=B->next;
	LinkList q=C->next;
	LinkList r=A->next;
	LinkList t;
	while(p&&q&&r){
		if(p->data<q->data)
			p=p->next;
		else if(p->data>q->data)
			q=q->next;
		else{
			u=p->data;//相同元素
			while(r->next->data<u)
				r=r->next;
			if(r->next->data=u){
				s=r->next;//A中要删除的相同元素
				while(s->data=u){//删除A中相同元素
					t=s;
					s=s->next;
					free(t);
				}
				r->next=s;//删除了A中所有的相同元素
			}
			while(p->data==u) 
				p=p->next;
			while(q->data==u)
				q=q->next;
		}
	}
	
}