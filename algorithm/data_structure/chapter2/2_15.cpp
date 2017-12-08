void concatList(LinkList la,LinkList lb,LinkList &lc){
	//把lb链接在la的后面
	LinkList p;
	lc=la;
	p=la;
	while(p->next)
		p=p->next;
	p->next=lb;
}