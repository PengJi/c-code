char c;	//全局变量，指示当前字符
int CreateCSTreeGList(CSTree &T){
	//由广义表形式的输入建立孩子兄弟链表
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