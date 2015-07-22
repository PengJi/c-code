int IsFull_Bitree(Bitree T){
	//判断二叉树是否完全二叉树,是则返回1,否则返回0
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