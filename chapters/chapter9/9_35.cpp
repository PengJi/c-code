void Print_Between(BiThrTree T,int a,int b){
	//��ӡ��������������������T �����д���a ��С��b ��Ԫ��
	p=T;
	while(!p->ltag) 
		p=p->lchild; //�ҵ���СԪ��
	while(p&&p->data<b){
		if(p->data>a) 
			printf("%d\n",p->data); //�������������Ԫ��
		if(p->rtag) 
			p=p->rtag;
		else{
			p=p->rchild;
			while(!p->ltag) p=p->lchild;
		}
	}
}