Status Print_Expression(Bitree T){
	//按标准形式输出以二叉树存储的表达式
	if(T->data 是字母) 
		printf("%c",T->data);
	else if(T->data 是操作符){
		if(!T->lchild||!T->rchild) 
			return ERROR; 
		if(T->lchild->data 是操作符&&T->lchild->data 优先级低于T->data){
			printf("(");
			if(!Print_Expression(T->lchild)) 
				return ERROR;
			printf(")");
		} 
		else if(!Print_Expression(T->lchild)) 
			return ERROR;
		if(T->rchild->data 是操作符&&T->rchild->data 优先级低于T->data){
			printf("(");
			if(!Print_Expression(T->rchild)) 
				return ERROR;
			printf(")");
		}
		else if(!Print_Expression(T->rchild))
			return ERROR;
	}
	else return ERROR; 
	return OK;
}