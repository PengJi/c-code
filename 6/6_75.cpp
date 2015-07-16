char c;
int pos=0;
int CreateCTreeGList(CTree &T,int &i){
	//由广义表形式的输入建立孩子链表
	c=getchar();
	T.nodes[pos].data=c;
	i=pos++;
	if((c=getchar()) == '('){
		CreateCTreeGList();
		p=(CTBox*) malloc(sizeof(CTBox));
		T.nodes[i].firstchild=p;
		p->child=pos;
		for(;c=',';p=p->next){
			CreateCTreeGList(T,j);
			p->child=j;
			p->next=(CTBox*) malloc (sizeof(CTBox));
		}
		p->next=NULL;
		if((c=getchar())!=')')
			return 0;
	}else{
		T.nodes[i].firstchild=NULL;
	}

	return 1;
}