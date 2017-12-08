void LayerOrder(Bitree T){
	//²ãÐò±éÀú¶þ²æÊ÷
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