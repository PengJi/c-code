int last=0;
void MaxLT_MinGT(BiTree T,int x){
	//�ҵ�����������T ��С��x �����Ԫ�غʹ���x ����СԪ��
	if(T->lchild) 
		MaxLT_MinGT(T->lchild,x);
	if(last<x&&T->data>=x) //�ҵ���С��x �����Ԫ��
		printf("a=%d\n",last);
	if(last<=x&&T->data>x) //�ҵ��˴���x ����СԪ��
		printf("b=%d\n",T->data);
	last=T->data;
	if(T->rchild) 
		MaxLT_MinGT(T->rchild,x);
}