//二叉树的顺序存储结构
#define MAX_TREE_SIZE 100 //二叉树的最大结点数
typedef TElemType SqBiTree[MAX_TREE_SIZE]; //0号单元存储根结点
SqBiTree bt;

//二叉树的二叉链表存储表示
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//二叉树的二叉线索存储表示
typedef enum PointerTag{Link,Thread}; //Link==0，指针；Thread==1，线索
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild; //左右孩子指针
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;

//树的双亲表存储表示
#define MAX_TREE_SIZE 100
typedef struct PTNode{ //结点结构
	TElemType data;
	int parent; //双亲位置域
}PTNode;
typedef struct{ //树结构
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;
}PTree;

//树的孩子链表存储表示
typedef struct CTNode{ //孩子结点
	int child;
	struct CTNode *next;
}*ChildPtr;
typedef struct{
	TElemType data;
	childPtr firstchild; //孩子链表头指针
}CTBox;
typedef struct{
	CTBox nodes[MAX_TREE_SIZE];
	int n,r; //结点数和根的位置
}CTree;

//树的二叉链表(孩子-兄弟)存储表示
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild,*nextsiblind;
}CSNode,*CSTree;
