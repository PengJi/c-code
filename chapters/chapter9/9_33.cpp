void Print_NLT(BiTree T,int x){
	//�Ӵ�С�������������T �����в�С��x ��Ԫ��
	if(T->rchild) 
		Print_NLT(T->rchild,x);
	if(T->data<x) 
		exit(); //������С��x ��Ԫ��ʱ������������
	printf("%d\n",T->data);
	if(T->lchild) 
		Print_NLT(T->lchild,x); //���Һ�����������
}