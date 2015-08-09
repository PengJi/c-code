void BSTree_Merge(BiTree &T,BiTree &S){
	//�Ѷ���������S �ϲ���T ��
	if(S->lchild) 
		BSTree_Merge(T,S->lchild);
	if(S->rchild) 
		BSTree_Merge(T,S->rchild); //�ϲ�����
	Insert_Key(T,S); //����Ԫ��
}
void Insert_Node(Bitree &T,BTNode *S){
	//�������S ���뵽T �ĺ���λ����
	if(S->data>T->data){
		if(!T->rchild) 
			T->rchild=S;
		else 
			Insert_Node(T->rchild,S);
	}
	else if(S->data<T->data){
		if(!T->lchild)
			T->lchild=S;
		else 
			Insert_Node(T->lchild,S);
	}
	S->lchild=NULL; //������½������ԭ�������������Ͼ���ϵ
	S->rchild=NULL; //����ᵼ�����ṹ�Ļ���
}