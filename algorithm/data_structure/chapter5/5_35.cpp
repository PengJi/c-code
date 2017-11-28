int CreateGList(GList &L){
	//根据输入创建广义表L
	cin>>ch;
	if(ch==''){
		L=NULL;
		cin>>ch;
		if(ch!=')')
			return 0;
		return 1;
	}
	L=(GList) malloc(sizeof(GLNode));
	L->tag=1;
	if(isalphabet(ch)){
		p=(GList)malloc(sizeof(GLNode));
		p->tag=0;
		p->atom=ch;
		L->ptr.hp=p;
	}else if(ch=='(')
		CreateGList(L->ptr.hp);
	else return 0;
	cin>>ch;
	if(ch==')')
		L->ptr.tp=NULL;
	else if(ch==',')
		CreateGList(L->ptr.tp);
	else return 0;
	return 1;
}