typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int sameDelete(LinkList &L){
	//ɾ������������L��ֵ��ͬ��Ԫ��
	LinkList p,q,r;
	p=L->next;
	q=p->next;
	while(p->next){
		if(p->data!=q->data){
			p=p->next;
			q=p->next;
		}else{
			while(p->data==q->data){
				r=q;
				q=q->next;
				free(r);
			}
			p->next=q;
			p=q;
			q=p->next;
		}
	}
}