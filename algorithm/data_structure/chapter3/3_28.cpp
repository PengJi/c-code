typedef struct{
	ElemType data;
	LinkNode *next;
}LinkNode,*LinkQueue;
void InitQueue(LinkQueue &q){//��ʼ������ 
	Q=(LinkNode *) malloc(sizeof(LinkNode));
	Q->next=Q;
}
void enQueue(LinkQueue &q,int x){
	//�����
	//qָ��ѭ�����ж�βԪ�ؽ��
	p=(LinkNode *) malloc(sizeof(LinkNode));
	p->data=x;
	p-next=q->next;
	q->next=p;
	q=p;
}
int deQueue(LinkQueue &q,int &x){
	//������
	//qָ��ѭ�����ж�βԪ�ؽ��
	//���������ֻ��һ��Ԫ�أ����������⴦��
	LinkQueue p;
	if(q=q->next){//�ӿ�
		return 0;
	}
	if(q=q->next->next){//ֻ��һ��Ԫ��
		x=q->data;
		q=q->next;
	}
	p=q->next->next;
	x=p->data;
	q->next->next=p->next;
	free(p);
	return 1;
}

