void concatList(LinkList la,LinkList lb,LinkList &lc){
	//��lb������la�ĺ���
	LinkList p;
	lc=la;
	p=la;
	while(p->next)
		p=p->next;
	p->next=lb;
}