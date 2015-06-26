#define MaxSize 50
//˳��ջ
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;
//��ʽջ
typedef struct Linknode{
	ElemType data;
	struct Linknode *next;
}*LiStack;

//���е�˳��洢
typedef struct{
	ElemType data[MaxSize];
	int front,rear;
}SqQueue;
//���е���ʽ�洢
typedef struct{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front,*rear;
}LinkQueue;