void GListPrint(GList A){
	//输出广义表
	if(!A)
		cout<<"()";
	else if(!A->tag)
		cout<<A->atom;
	else{
		cout<<"(";
		for(p=A;p;p=p->ptr.tp){
			GListPrint(p->ptr.hp);
			if(p->ptr.tp)
				cout<<",";
		}
		cout<<")";
	}
}