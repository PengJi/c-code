void GListPrint(GList A){
	//��������
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