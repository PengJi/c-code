int DescNum(Bitree T){
	//�������T ��������������DescNum ����,�����ظ���
	if(!T) 
		return -1;
	else 
		d=(DescNum(T->lchild)+DescNum(T->rchild)+2); 
	T->DescNum=d;
	return d;
}