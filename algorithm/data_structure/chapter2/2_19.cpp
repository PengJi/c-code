typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList
int betweenDelete(LinkList &L,int mink,int maxk){
	//ɾ������������ֵλ��mink��maxk֮��Ľڵ�
	LinkList p,q,r;
	p-L;
	while(p->next->data<=mink)//�������һ��С��mink����
		p=p->next;
	if(p->next){
		q=p->next;
		while(q->data<maxk){//�������һ��С��maxk����
			r=q;
			q=q->next;
			free(r);
		}
		p->next=q;
	}
	return 0;
}