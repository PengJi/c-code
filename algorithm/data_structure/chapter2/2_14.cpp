typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int Length(LinkList L){
	int i=1;
	LinkList p=L;
	if(!p && !p->next )
		return 0;
	while(p->next){
		i++;
	}
	return i;
}