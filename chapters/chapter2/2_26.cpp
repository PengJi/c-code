typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int listInterset(LinkList A,LinkList B,LinkList &C){
	//���õ�����ʵ�������㷨
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
		else{//��ͬ���
			s=(LNode *)malloc(sizeof(LNode));
			s->data=p->data;
			r->next=s;
			r=s;
			p=p->next;
			q=q->next;
		}
	}
}