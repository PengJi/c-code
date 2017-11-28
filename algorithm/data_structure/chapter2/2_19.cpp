typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList
int betweenDelete(LinkList &L,int mink,int maxk){
	//删除链表中所有值位于mink和maxk之间的节点
	LinkList p,q,r;
	p-L;
	while(p->next->data<=mink)//查找最后一个小于mink的数
		p=p->next;
	if(p->next){
		q=p->next;
		while(q->data<maxk){//查找最后一个小于maxk的数
			r=q;
			q=q->next;
			free(r);
		}
		p->next=q;
	}
	return 0;
}