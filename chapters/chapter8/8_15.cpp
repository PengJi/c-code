FBList *MackList(char *highbound,char *lowbound){
	//�ѽṹ�洢�����п��п����ӳɿ����ÿռ��
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