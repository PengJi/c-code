int IsFull_Bitree(Bitree T){
	//�ж϶������Ƿ���ȫ������,���򷵻�1,���򷵻�0
	InitQueue(Q);
	flag=0;
	EnQueue(Q,T);
	while(!QueueEmpty(Q))
	{
		DeQueue(Q,p);
		if(!p) 
			flag=1;
		else if(flag) 
			return 0;
		else{
			EnQueue(Q,p->lchild);
			EnQueue(Q,p->rchild);
		}
	}
	return 1;
}