int DescNum(Bitree T){
	//求树结点T 的子孙总数填入DescNum 域中,并返回该数
	if(!T) 
		return -1;
	else 
		d=(DescNum(T->lchild)+DescNum(T->rchild)+2); 
	T->DescNum=d;
	return d;
}