int CreateBiTreeGList(BiTree &T){
	//�ɹ������ʽ�����뽨����������
	c=getchar();
	if(c=='#')
		T=NULL;
	else{
		T=(CSNode *) malloc(sizeof(CSNode));
		T->data=c;
		if(getchar()!='(')
			return 0;
		if(!CreateBiTreeGList(p1))
			return 0;
		T->lchild=p1;
		if(getchar()!=',')
			return 0;
		if(!CreateBiTreeGList(pr))
			return 0;
		T->child=pr;
		if(getchar()!=')')
			return 0;
	}
	return 1;
}