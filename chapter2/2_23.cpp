typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int listMerge(LinkList &A,LinkList &B){
	//�ϲ�������A��BΪC��C�е�Ԫ����A��BԪ�ؼ�����У�ʹ��A��B�Ĵ洢�ռ�
	//һ�μ������A��B��Ԫ�أ�������ϳ������Ԫ��
	//������ͷ���
	if(!A && !B)
		return 0;
	LinkList p,q,C,r,t;
	p=A->next;
	q=B->next;
	C=A;
	while(p&&q){
		r=p->next;//����ָ��
		p->next=q;//����B��Ԫ��
		if(r){
			t=q->next;
			q->next=r;
		}
		p=r;
		q=t;
	}
	return 1;
}