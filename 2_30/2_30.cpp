typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int deleteSameNode(LinkList &A,LinkList &B,LinkList &C){
	//ͬ���⣬�洢�ṹ��Ϊ���������ͷ���
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
			u=p->data;//��ͬԪ��
			while(r->next->data<u)
				r=r->next;
			if(r->next->data=u){
				s=r->next;//A��Ҫɾ������ͬԪ��
				while(s->data=u){//ɾ��A����ͬԪ��
					t=s;
					s=s->next;
					free(t);
				}
				r->next=s;//ɾ����A�����е���ͬԪ��
			}
			while(p->data==u) 
				p=p->next;
			while(q->data==u)
				q=q->next;
		}
	}
	
}