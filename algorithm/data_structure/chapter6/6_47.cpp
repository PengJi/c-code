void LayerOrder(Bitree T){
	//�������������
	InitQueue(Q);
	EnQueue(Q,T);
	while(!QueueEmpty(Q)){
		DeQueue(Q,p);
		visit(p);
		if(p->lchild) 
			EnQueue(Q,p->lchild);
		if(p->rchild) 
			EnQueue(Q,p->rchild);
	}
}