void GListPrintLOrder(GList A){
	//������������A�е�����Ԫ��
	InitQueue(Q);
	for(p=L;p;p=p->ptr.tp)
		EnQueue(Q,p);
	while(!QueueEmpty(Q)){
		DeQueue(Q,r);
		if(!r->tag)
			cout<<r->atom;
		else
			for(r=r->ptr.hp;r;r=r->ptr.tp)
				EnQueue(Q,r);
	}
}