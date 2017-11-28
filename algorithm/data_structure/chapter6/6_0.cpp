//��������˳��洢�ṹ
#define MAX_TREE_SIZE 100 //���������������
typedef TElemType SqBiTree[MAX_TREE_SIZE]; //0�ŵ�Ԫ�洢�����
SqBiTree bt;

//�������Ķ�������洢��ʾ
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//�������Ķ��������洢��ʾ
typedef enum PointerTag{Link,Thread}; //Link==0��ָ�룻Thread==1������
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild; //���Һ���ָ��
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;

//����˫�ױ�洢��ʾ
#define MAX_TREE_SIZE 100
typedef struct PTNode{ //���ṹ
	TElemType data;
	int parent; //˫��λ����
}PTNode;
typedef struct{ //���ṹ
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;
}PTree;

//���ĺ�������洢��ʾ
typedef struct CTNode{ //���ӽ��
	int child;
	struct CTNode *next;
}*ChildPtr;
typedef struct{
	TElemType data;
	childPtr firstchild; //��������ͷָ��
}CTBox;
typedef struct{
	CTBox nodes[MAX_TREE_SIZE];
	int n,r; //������͸���λ��
}CTree;

//���Ķ�������(����-�ֵ�)�洢��ʾ
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild,*nextsiblind;
}CSNode,*CSTree;
