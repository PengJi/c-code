#define MaxSize 50
//顺序栈
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;
//链式栈
typedef struct Linknode{
	ElemType data;
	struct Linknode *next;
}*LiStack;

//队列的顺序存储
typedef struct{
	ElemType data[MaxSize];
	int front,rear;
}SqQueue;
//队列的链式存储
typedef struct{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front,*rear;
}LinkQueue;