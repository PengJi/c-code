typedef struct{
	ElemType data;
	LNode *next;
	LNode *pre;
}LNode,*LinkList;
int change2dul(LinkList &L){
	//��ѭ���������Ϊ˫��ѭ������
	LinkList p;
	p=L;
	if(!p)
		return 0;
	while(!p->next->pre){
		p->next->pre=p;
		p->next;
	}
	return 1;
}