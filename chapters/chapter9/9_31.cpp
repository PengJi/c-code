int last=0,flag=1;
int Is_BSTree(Bitree T){
	//�ж϶�����T �Ƿ����������,���򷵻�1,���򷵻�0
	if(T->lchild&&flag) 
		Is_BSTree(T->lchild);
	if(T->data<last)
		flag=0; //��������ǰ����Ƚ�
	last=T->data;
	if(T->rchild&&flag) 
		Is_BSTree(T->rchild);
	return flag;
}