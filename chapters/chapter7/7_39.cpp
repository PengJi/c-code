void PrintNiBoLan_Bitree(Bitree T){
	//�ڶ�������洢�ṹ��������һ��
	if(T->lchild) 
		PrintNiBoLan_Bitree(T->lchild);
	if(T->rchild) 
		PrintNiBoLan_Bitree(T->rchild);
	printf("%c",T->data);
}