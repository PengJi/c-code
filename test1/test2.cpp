#define MaxSize 50
//静态分配
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;
//动态分配
typedef struct{
	ElemType *data;
	int length;
}

//单链表
typedef struct{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
//双链表
typedef struct{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*LinkList;
//静态链表
typedef struct{
	ElemType data;
	int next;//存储数据的元素下标
}SLinkList[MaxSize];