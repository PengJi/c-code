//数组的顺序存储表示
#define MAX.ARRAY.DIM 8 //假设数组维数最大值为8
typedef struct{
	ElemType *base; //数组元素基址
	int dim; //数组维数
	int *bounds; //数组的维界基址
	int *constants; //数组映像函数常量基址
}Array;

//稀疏矩阵的三元组顺序表存储表示
#define MAXSIZE 12500 //假设非零元个数的最大值为12500
typedef struct{
	int i,j; //非零元的行下标和列下表
	ElemType e;
}Triple;
typedef struct{
	Triple data[MAXSIZE+1]; //非零元三元组表，data[0]未用
	int mn,nu,tu; //矩阵的行数、列数和非零元个数
}TSMatrix;

//稀疏矩阵的十字链表存储
typedef struct OLNode{
	int i,j; //非零元的行下标和列下表
	ElemType e;
	struct OLNode *right,*down; //该非零元所在行表和列表的后继链域
}OLNode,*OLink;
typedef struct{
	OLink *rhead,*chead; //行和列链表头指针向量基址
	int mn,nu,tu; //稀疏矩阵的行数、列数和非零元个数
}CrossList;

//广义表的头尾链表存储表示
typedef enum {ATOM,LIST} ElemType; //ATOM==0,原子;LIST==1,子表
typedef struct GLNode{
	ElemType tag;//公共部分，用于区分原子节点和表节点
	union{ //原子节点和表节点的联合部分
		AtomType atom; //atom是原子节点的值域，AtomType由用户定义
		struct {struct GLNode *hp,*tp} ptr; //ptr是表节点的指针域，ptr.hp和ptr.tp分别只想表头和表尾
	};
}*GList;

//广义表的扩展线性链表存储表示
typedef enum {ATOM,LIST} ElemType; //ATOM==0,原子;LIST==1,子表
typedef struct GLNode{
	ElemTag tag; //公共部分，用于区分原子节点和表节点
	union{ //原子结点和表结点的联合部分
		AtomType atom; //原子结点的值域
		struct GLNode *hp; //表结点的表头指针
	};
	struct GLNode *tp; //相当于线性链表的next,指向下一个元素结点
}*GList;

