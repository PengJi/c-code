int CreateBiTreeGList(BiTree &T){
	//由广义表形式的输入建立二叉链表
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