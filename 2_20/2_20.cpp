typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int sameDelete(LinkList &L){
	//删除递增的链表L中值相同的元素
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