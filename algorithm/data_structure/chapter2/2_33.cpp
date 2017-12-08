typedef struct{
	Elem data;
	LNode *next;
}LNode,*LinkList
int divideList(LinkList &L,CirList &A,CirList &B,CirList &C){
	//将一个单链表按元素的类型分为三个循环链表A,B,C
	s=L->next;
	A=(CirNode *)malloc(sizeof(CirNode));
	p=A;
	B=(CirNode *)malloc(sizeof(CirNode));
	q=B;
	C=(CirNode *)malloc(sizeof(CirNode));
	while(s){
		if(isAlphabet(s->data)){
			p->next=s;
			p=s;
		}else if(isDigit(s->data)){
			q->next=s;
			q=s;
		}else{
			r->next=s;
			r=s;
		}
	}
	p->next=A;
	q->next=B;
	r->next=C;
}