typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int deleteNode(LinkList s){
	//ɾ����ѭ�������н��s��ǰ�����
	LinkList p=s;
	while(p->next->next!=s)
		p=p->next;
	return 1;
}