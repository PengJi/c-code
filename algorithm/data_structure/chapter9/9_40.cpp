typedef struct {
	int data;
	int bf;
	int lsize; 
	BlcNode *lchild,*rchild;
} BlcNode,*BlcTree; 
BTNode *Locate_BlcTree(BlcTree T,int k){
	//�ں�lsize ���ƽ�����������T ��ȷ����k С�Ľ��ָ��
	if(!T) 
		return NULL; 
	if(T->lsize==k)
		return T; 
	else if(T->lsize>k)
		return Locate_BlcTree(T->lchild,k); //����������Ѱ��
	else 
		return Locate_BlcTree(T->rchild,k-T->lsize); //����������Ѱ��,ע��Ҫ�޸�k ��ֵ
}