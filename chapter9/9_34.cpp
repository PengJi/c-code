void Delete_NLT(BiTree &T,int x){
	//ɾ������������T �����в�С��x Ԫ�ؽ��,���ͷſռ�
	if(T->rchild) 
		Delete_NLT(T->rchild,x);
	if(T->data<x) 
		exit(); //������С��x ��Ԫ��ʱ������������
	q=T;
	T=T->lchild;
	free(q); //���������С��x,��ɾ������,�����������ĸ���Ϊ�µ�����
	if(T) 
		Delete_NLT(T,x);
}