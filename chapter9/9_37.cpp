Status BSTree_Delete_key(BiThrTree &T,int x){
	//�ں����������������T ��ɾ��Ԫ��x
	BTNode *pre,*ptr,*suc;//ptr Ϊx ���ڽ��,pre ��suc �ֱ�ָ��ptr ��ǰ���ͺ��
	p=T;last=NULL; //last ʼ��ָ��ǰ���p ��ǰһ��(ǰ��)
	while(!p->ltag) 
		p=p->lchild; //�ҵ�������ʼԪ��
	while(p){
		if(p->data==x){ //�ҵ���Ԫ��x ���
			pre=last;
			ptr=p;
		}
		else if(last&&last->data==x) 
			suc=p; //�ҵ���x �ĺ��
		if(p->rtag) 
			p=p->rtag;
		else{
			p=p->rchild;
			while(!p->ltag) 
				p=p->lchild;
		} //ת��������
		last=p;
	}
	if(!ptr) 
		return ERROR; //δ�ҵ���ɾ���
	Delete_BSTree(ptr); //ɾ��x ���
	if(pre&&pre->rtag)
		pre->rchild=suc; //�޸�����
	return OK;
}
void Delete_BSTree(BiThrTree &T){
	//�α��ϸ�����ɾ������������������T ���㷨,���������������Ľṹ����һЩ�Ķ�
	q=T;
	if(!T->ltag&&T->rtag) //�����������,��ʱֻ���ؽ���������
		T=T->lchild;
	else if(T->ltag&&!T->rtag) //�����������,��ʱֻ���ؽ���������
		T=T->rchild;
	else if(!T->ltag&&!T->rtag){ //����������������������
		p=T;r=T->lchild;
		while(!r->rtag){
			s=r;
			r=r->rchild; 
		}
		T->data=r->data; 
		if(s!=T)
			s->rchild=r->lchild;
		else 
			s->lchild=r->lchild; //�ؽ�r ������������˫�׽����
		q=r;
	}
	free(q); //ɾ�����
}