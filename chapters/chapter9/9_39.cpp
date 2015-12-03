void BSTree_Split(BiTree &T,BiTree &A,BiTree &B,int x){
	//�Ѷ���������T ����Ϊ���ö���������A ��B,����A ��Ԫ��ȫ��С�ڵ���x,B ��Ԫ��ȫ������x
	if(T->lchild)
		BSTree_Split(T->lchild,A,B,x);
	if(T->rchild)
		BSTree_Split(T->rchild,A,B,x); //������������
	if(T->data<=x) 
		Insert_Node(A,T);
	else 
		Insert_Node(B,T); //��Ԫ�ؽ�������ʵ�����
}
void Insert_Node(Bitree &T,BTNode *S){
	//�������S ���뵽T �ĺ���λ����
	if(!T) T=S;
	else if(S->data>T->data){
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
	S->lchild=NULL;
	S->rchild=NULL;
}