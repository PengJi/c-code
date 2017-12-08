typedef struct{
	PolyTerm data;
	PolyNode *next;
}PolyNode,*PolyLink;
int divideList(PolyLink &L,PolyLink &A,PolyLink &B){
	//将一个循环链表分解成一个仅含奇次项和一个仅含偶次项的链表
	//遍历链表，奇次项存入一个链表，偶次项存入另一个链表
	p=L->next;
	A=(PolyNode *) malloc(sizeof(PolyNode));
	B=(PolyNode *) malloc(sizeof(PolyNode));
	pa=A;pb=B;
	while(p!=L){
		if((p->data.exp%2)!=0){
			pa->next=p;
			pa=p;
		}else{
			pb->next=p;
			pb=p;
		}
		p=p->next;
	}
	pa->next=A;
	pb->next=B;
}