void BSTree_Insert_Key(BiThrTree &T,int x){
	//�ں����������������T �в���Ԫ��x
	if(T->data<x){
		if(T->rtag) {
			p=T->rchild;
			q=(BiThrNode*)malloc(sizeof(BiThrNode));
			q->data=x;
			T->rchild=q;T->rtag=0;
			q->rtag=1;q->rchild=p;
		}
		else 
			BSTree_Insert_Key(T->rchild,x);
	}
	else if(T->data>x){ //���뵽��������
		if(!T->lchild){ //T û��������ʱ,��Ϊ���Ӳ���
			q=(BiThrNode*)malloc(sizeof(BiThrNode));
			q->data=x;
			T->lchild=q;
			q->rtag=1;q->rchild=T; //�޸����������
		}
		else 
			BSTree_Insert_Key(T->lchild,x);//T ��������ʱ,������������
	}
}