void PreOrder_Nonrecursive(Bitree T){
	//��������������ķǵݹ��㷨
	InitStack(S);
	Push(S,T);
	while(!StackEmpty(S)){
		while(Gettop(S,p)&&p){
			visit(p->data);
			push(S,p->lchild);
		}
		pop(S,p);
		if(!StackEmpty(S)){
			pop(S,p);
			push(S,p->rchild);
		}
	}
}