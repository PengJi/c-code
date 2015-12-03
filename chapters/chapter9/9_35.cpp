void Print_Between(BiThrTree T,int a,int b){
	//打印输出后继线索二叉排序树T 中所有大于a 且小于b 的元素
	p=T;
	while(!p->ltag) 
		p=p->lchild; //找到最小元素
	while(p&&p->data<b){
		if(p->data>a) 
			printf("%d\n",p->data); //输出符合条件的元素
		if(p->rtag) 
			p=p->rtag;
		else{
			p=p->rchild;
			while(!p->ltag) p=p->lchild;
		}
	}
}