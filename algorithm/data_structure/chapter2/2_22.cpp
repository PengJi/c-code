typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
LinkList ReverseList(LinkList &L){
	//����ͷ���ĵ�����͵�����
	//����ͷ�巨���������ͷ���ժ�£�Ȼ�������ΰ�����ĸ���������ͷ���ĺ���
	LinkList r;
	p=L->next;
	L->next=NULL;
	while(p!=NULL){
		r=p->next;
		p->next=L->next;
		L->next=p;
		p=r;
	}
	return L;
}