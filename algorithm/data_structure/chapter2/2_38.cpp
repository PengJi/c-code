typedef struct{
	ElemType data;
	DNode *prier,*next;
	int freq;
}DNode,*DLinkList;
DLinkList locate(DLinkList &L,ElemType x){
	//����ѭ��˫�����е�����x�����ҳɹ�freq+1����������㰴freq�ݼ�����
	DNode *p=L->next,*q;
	while(p&&p->data !=x)
		p=p->next;
	if(!p){//��㲻����
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
