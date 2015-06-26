typedef struct xorNode{
	char data;
	struct xorNode *LRPtr;
}xorNode,*xorPoint;
typedef struct{
	xorPoint left,right;
}xorLinkedList;
void printNode(xorLinkdList L){
	//从左向右或从右向左输出异或链表的结点值
	xorPoint p,q;
	p=L.left;
	pre=NULL;
	while(p){
		cout<<p->data;
		q=XorP(p->LRPtr,pre);//进行异或运算,得到右结点指针
		pre=p;
		p=q;
	}
}