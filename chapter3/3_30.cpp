typedef struct{
	ElemType base[MaxSize];
	int rear;
	int length;
}Queue;//将长度的循环队列
//队满条件：length=MaxSize
int enQueue(Queue &Q,int x){
	//循环队列入队
	if(Q.length==MazSize)//队满
		return 0;
	Q.rear=(Q.rear+1)%MaxSize;
	Q.base[Q.rear]=x;
	Q.length++;
	return 1;
}
int deQueue(Queue &Q,int &x){
	//循环队列出队
	if(Q.length==0)
		return 0;
	head=((Q.rear+MaxSize)-Q.length+1)%MaxSize;//算头结点的位置
	x=Q.base[head];
	Q.length--;
}