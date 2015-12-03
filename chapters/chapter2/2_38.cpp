typedef struct{
	ElemType data;
	DNode *prier,*next;
	int freq;
}DNode,*DLinkList;
DLinkList locate(DLinkList &L,ElemType x){
	//查找循环双链表中的数据x，查找成功freq+1，最后将链表结点按freq递减排序
	DNode *p=L->next,*q;
	while(p&&p->data !=x)
		p=p->next;
	if(!p){//结点不存在
		exit(0);
	}else{
		p->freq++;
		p->next->prier=p->prier;
		p->prier->next=p->next;
		q=p->prier;
		while(q!=L&&q->freq<=p->freq)
			q=q->prier;
		p->next=q->next;
		q->next->prier=p;
		p->prier=q;
		q->next=p;
	}
	return p;
}
