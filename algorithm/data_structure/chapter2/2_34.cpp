typedef struct xorNode{
	char data;
	struct xorNode *LRPtr;
}xorNode,*xorPoint;
typedef struct{
	xorPoint left,right;
}xorLinkedList;
void printNode(xorLinkdList L){
	//�������һ������������������Ľ��ֵ
	xorPoint p,q;
	p=L.left;
	pre=NULL;
	while(p){
		cout<<p->data;
		q=XorP(p->LRPtr,pre);//�����������,�õ��ҽ��ָ��
		pre=p;
		p=q;
	}
}