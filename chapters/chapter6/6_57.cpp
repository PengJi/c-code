Bitree PostOrder_Next(Bitree p){
	//�ں����������������в��ҽ��p �ĺ�����,������ָ��
	if(p->rtag) 
		return p->rchild; //p �к������
	else if(!p->parent) 
		return NULL; //p �Ǹ����
	else if(p==p->parent->rchild) 
		return p->parent; //p ���Һ���
	else if(p==p->parent->lchild&&p->parent->rtag)
		return p->parent; //p ��������˫��û���Һ���
	else{ //p ��������˫�����Һ���
		q=p->parent->rchild;
		while(q->lchild||!q->rtag){
			if(q->lchild) q=q->lchild;
			else q=q->rchild;
		} //��p ��˫�׵��Һ��������ߵ���
		return q;
	}
}