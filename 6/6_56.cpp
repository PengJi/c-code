BTNode *PreOrder_Next(BTNode *p){
	//�������������������в��ҽ��p ��������,������ָ��
	if(p->lchild) 
		return p->lchild;
	else 
		return p->rchild;
}