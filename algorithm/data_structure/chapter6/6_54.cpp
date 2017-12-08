int CreateBitree_SqList(Bitree &T,SqList sa){
	//根据顺序存储结构建立二叉链表
	Bitree ptr[sa.last+1]; //该数组储存与sa 中各结点对应的树指针
	if(!sa.last){
		T=NULL; 
		return 0;
	}
	ptr[1]=(BTNode*)malloc(sizeof(BTNode));
	ptr[1]->data=sa.elem[1];
	T=ptr[1];
	for(i=2;i<=sa.last;i++){
		if(!sa.elem[i]) 
			return 0; 
		ptr[i]=(BTNode*)malloc(sizeof(BTNode));
		ptr[i]->data=sa.elem[i];
		j=i/2;
		if(i-j*2) 
			ptr[j]->rchild=ptr[i]; 
		else 
			ptr[j]->lchild=ptr[i]; 
	}
	return 1;
}