FBList *MackList(char *highbound,char *lowbound){
	//堆结构存储的所有空闲块链接成可利用空间表
	p=lowbound;
	while(p->tag && p<highbound)
		p++;
	if(p>=highbound)
		return NULL;
	head=p;
	for(q=p;p<highbound;p+=cellsize){
		if(!p->tag){
			q->next=p;
			q=p;
		}
		p->next=NULL;
		return head;
	}
}