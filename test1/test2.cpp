#define MaxSize 50
//��̬����
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;
//��̬����
typedef struct{
	ElemType *data;
	int length;
}

//������
typedef struct{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
//˫����
typedef struct{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*LinkList;
//��̬����
typedef struct{
	ElemType data;
	int next;//�洢���ݵ�Ԫ���±�
}SLinkList[MaxSize];