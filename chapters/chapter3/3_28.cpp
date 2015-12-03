typedef struct{
	ElemType data;
	LinkNode *next;
}LinkNode,*LinkQueue;
void InitQueue(LinkQueue &q){//初始化队列 
	Q=(LinkNode *) malloc(sizeof(LinkNode));
	Q->next=Q;
}
void enQueue(LinkQueue &q,int x){
	//入队列
	//q指向循环队列队尾元素结点
	p=(LinkNode *) malloc(sizeof(LinkNode));
	p->data=x;
	p-next=q->next;
	q->next=p;
	q=p;
}
int deQueue(LinkQueue &q,int &x){
	//出队列
	//q指向循环队列队尾元素结点
	//如果队列中只有一个元素，则另作特殊处理。
	LinkQueue p;
	if(q=q->next){//队空
		return 0;
	}
	if(q=q->next->next){//只有一个元素
		x=q->data;
		q=q->next;
	}
	p=q->next->next;
	x=p->data;
	q->next->next=p->next;
	free(p);
	return 1;
}

