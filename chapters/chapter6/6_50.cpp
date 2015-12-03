Status CreateBitree_Triplet(Bitree &T){
	//输入三元组建立二叉树
	if(getchar()!='^') 
		return ERROR;
	T=(BTNode*)malloc(sizeof(BTNode));
	p=T;p->data=getchar();
	getchar(); 
	InitQueue(Q);
	EnQueue(Q,T);
	while((parent=getchar())!='^'&&(child=getchar())&&(side=getchar())){
		while(QueueHead(Q)!=parent&&!QueueEmpty(Q)) DeQueue(Q,e);
		if(QueueEmpty(Q)) 
			return ERROR; 
		p=QueueHead(Q);
		q=(BTNode*)malloc(sizeof(BTNode));
		if(side=='L') 
			p->lchild=q;
		else if(side=='R')
			p->rchild=q;
		else 
			return ERROR; 
		q->data=child;
		EnQueue(Q,q);
	}
	return OK;
}