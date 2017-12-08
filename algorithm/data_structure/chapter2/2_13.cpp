typedef struct	LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
int Locate(LinkList &L,ElemType x){
	int i=0;
	LinkList p=L;
	while(p&&p->data!=x){
		p=p->next;
		i++;
	}
	if(p)
		return i;
	else
		return 0;
		
}