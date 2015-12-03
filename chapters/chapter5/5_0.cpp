//�����˳��洢��ʾ
#define MAX.ARRAY.DIM 8 //��������ά�����ֵΪ8
typedef struct{
	ElemType *base; //����Ԫ�ػ�ַ
	int dim; //����ά��
	int *bounds; //�����ά���ַ
	int *constants; //����ӳ����������ַ
}Array;

//ϡ��������Ԫ��˳���洢��ʾ
#define MAXSIZE 12500 //�������Ԫ���������ֵΪ12500
typedef struct{
	int i,j; //����Ԫ�����±�����±�
	ElemType e;
}Triple;
typedef struct{
	Triple data[MAXSIZE+1]; //����Ԫ��Ԫ���data[0]δ��
	int mn,nu,tu; //����������������ͷ���Ԫ����
}TSMatrix;

//ϡ������ʮ������洢
typedef struct OLNode{
	int i,j; //����Ԫ�����±�����±�
	ElemType e;
	struct OLNode *right,*down; //�÷���Ԫ�����б���б�ĺ������
}OLNode,*OLink;
typedef struct{
	OLink *rhead,*chead; //�к�������ͷָ��������ַ
	int mn,nu,tu; //ϡ�����������������ͷ���Ԫ����
}CrossList;

//������ͷβ����洢��ʾ
typedef enum {ATOM,LIST} ElemType; //ATOM==0,ԭ��;LIST==1,�ӱ�
typedef struct GLNode{
	ElemType tag;//�������֣���������ԭ�ӽڵ�ͱ�ڵ�
	union{ //ԭ�ӽڵ�ͱ�ڵ�����ϲ���
		AtomType atom; //atom��ԭ�ӽڵ��ֵ��AtomType���û�����
		struct {struct GLNode *hp,*tp} ptr; //ptr�Ǳ�ڵ��ָ����ptr.hp��ptr.tp�ֱ�ֻ���ͷ�ͱ�β
	};
}*GList;

//��������չ��������洢��ʾ
typedef enum {ATOM,LIST} ElemType; //ATOM==0,ԭ��;LIST==1,�ӱ�
typedef struct GLNode{
	ElemTag tag; //�������֣���������ԭ�ӽڵ�ͱ�ڵ�
	union{ //ԭ�ӽ��ͱ�������ϲ���
		AtomType atom; //ԭ�ӽ���ֵ��
		struct GLNode *hp; //����ı�ͷָ��
	};
	struct GLNode *tp; //�൱�����������next,ָ����һ��Ԫ�ؽ��
}*GList;

