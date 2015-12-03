typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int deleteNode(LinkList s){
	//删除单循环链表中结点s的前驱结点
	LinkList p=s;
	while(p->next->next!=s)
		p=p->next;
	return 1;
}