typedef struct{
	PolyTerm data;
	PolyNode *next;
}PolyNode,*PolyLink;
int derivative(PloyLink &L){
	//����ѭ������(��ͷ���)��Ϊ�洢�ṹ��ϡ�����ʽ�ĵ�����
	//ȥ�����еĳ�������д������䵼��
	//data.exp ������data.coef ϵ��
	if(!L->next)
		return 0;
	p=L->next;
	//���ڳ�����
	if(!p->data.exp){
		L->next=p->next;
		p=p->next;
	}
	while(p!=L){
		p->data.coef=p->data.coef*(p->data.exp--);
		p=p->next;
	}

	return 1;
}