Status Print_Expression(Bitree T){
	//����׼��ʽ����Զ������洢�ı��ʽ
	if(T->data ����ĸ) 
		printf("%c",T->data);
	else if(T->data �ǲ�����){
		if(!T->lchild||!T->rchild) 
			return ERROR; 
		if(T->lchild->data �ǲ�����&&T->lchild->data ���ȼ�����T->data){
			printf("(");
			if(!Print_Expression(T->lchild)) 
				return ERROR;
			printf(")");
		} 
		else if(!Print_Expression(T->lchild)) 
			return ERROR;
		if(T->rchild->data �ǲ�����&&T->rchild->data ���ȼ�����T->data){
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