typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int mergeReverse(LinkList &A,LinkList &B){
	//����������ĵ�����A��B�ϲ�Ϊ�ݼ����������C��ʹ��A��B�Ŀռ�
	//����A��B������С�����˳�����ΰ�Ԫ�ز���C��ͷ��
	if(!A || !B)
		return 0;
	LinkList pa,pb,p,q;
	LinkList pc;//pcָ���������ͷ��
	pa=A->next;
	pb=B->next;
	while(pa || pb){
		if(pa->data<pb->data){
			pc=pa;//����A��Ԫ��
			q=pa->next;
			pa->next=p;
			p=q;
		}else{
			pc=pb;//����B��Ԫ��
			q=pb->next;
			pb->next=p;
			pb=q;
		}
		p=pc;
	}
	C=A;
	A->next=pc;
}