typedef struct{
	PolyTerm data;
	PolyNode *next;
}PolyNode,*PolyLink;
int divideList(PolyLink &L,PolyLink &A,PolyLink &B){
	//��һ��ѭ������ֽ��һ������������һ������ż���������
	//����������������һ������ż���������һ������
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