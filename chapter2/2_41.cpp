typedef struct{
	PolyTerm data;
	PolyNode *next;
}PolyNode,*PolyLink;
int derivative(PloyLink &L){
	//求以循环链表(带头结点)作为存储结构的稀疏多项式的导函数
	//去掉其中的常数项，对有次项求其导数
	//data.exp 次数；data.coef 系数
	if(!L->next)
		return 0;
	p=L->next;
	//对于常数项
	if(!p->data.exp){
		L->next=p->next;
		p=p->next;
	}
	while(p!=L){
		p->data.coef=p->data.coef*(p->data.exp--);
		p=p->next;
	}

	return 1;
}