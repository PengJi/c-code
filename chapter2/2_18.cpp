void deleteList1(LinkList &L,int i){
	//ɾ������ͷ���ĵ�����ĵ�i�����
	LinkList p,q;
	q=L;
	if(i==1){
		L=L->next;
		free(q);
	}
	else{
		p=L;
		while(--i>1)
			p=p->next;
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
}
void deleteList2(LinkList &L,int i){
	//ɾ����ͷ���ĵ�������еĵ�i�����
	LinkList p,q;
	p=L->next;
	while(--i>1)
		p=p->next;
	q=p->next;
	p->next=p->next->next;
	free(q);
}