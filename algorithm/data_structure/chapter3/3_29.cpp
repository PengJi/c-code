typedef struct{
	ElemType base[MaxSize];
	int front;
	int rear;
	int tag;
}DQueue;
//当入队时，如果front=rear，则置tag=1 队满
//当出队时，如果front=rear，则置tag=0 队空
int enDQueue(DQueue &q,int x){
	//带tag的循环队列入队
	if(q.front==q.rear && q.tag==1)//队满
		return 0;
	q.rear=(q.rear+1)%MaxSize;
	q.base[q.rear]=x;
	if(q.front==q.rear)
		q.tag=1;
	return 1;
}
int deDQueue(DQueue &q,int &x){
	if(q.front==q.rear && q.tag==0)//队空
		return 0;
	x=q.base[q.front];
	q.front=(q.front+1)%MaxSize;
	if(q.front==q.rear)
		q.tag=0;
	return 1;
}