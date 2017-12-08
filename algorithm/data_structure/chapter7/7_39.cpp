void PrintNiBoLan_Bitree(Bitree T){
	//在二叉链表存储结构上重做上一题
	if(T->lchild) 
		PrintNiBoLan_Bitree(T->lchild);
	if(T->rchild) 
		PrintNiBoLan_Bitree(T->rchild);
	printf("%c",T->data);
}