typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int listInterset(LinkList A,LinkList B,LinkList &C){
	//利用单链表实现上述算法
	LinkList p,q,r,s;
	p=B->next;
	q=B->next;
	r=(LNode *) malloc (sizeof(LNode));
	C=r;
	while(p&&q){
		if(p->data<q->data)
			p=p->next;
		else if(p->data>q->data)
			q=q->next;
		else{//相同结点
			s=(LNode *)malloc(sizeof(LNode));
			s->data=p->data;
			r->next=s;
			r=s;
			p=p->next;
			q=q->next;
		}
	}
}