char c;	//ȫ�ֱ�����ָʾ��ǰ�ַ�
int CreateCSTreeGList(CSTree &T){
	//�ɹ������ʽ�����뽨�������ֵ�����
	c=getchar();
	T=(CSNode *)malloc(sizeof(CSNode));
	T->data = c;
	if((c=getchar()) == '('){
		if(!CreateCSTreeGList(fc)) return 0;
		T->firstchild = fc;
		for(p=fc;c==',';p->nextsib=nc,p=nc)
			if(!CreateCSTreeGList(nc))
				return 0;
		p->nextsib=NULL;
		if((c=getchar())!=')')
			return 0;
	}else{
		T->firstchild = NULL;
		return 1;
	}
}