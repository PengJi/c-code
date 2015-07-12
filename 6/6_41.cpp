int c,k;
void Get_PreSeq(Bitree T){
	//求先序序列为k 的结点的值
	if(T){
		c++; 
		if(c==k){
			printf("Value is %d\n",T->data);
			exit (1);
		}else{
			Get_PreSeq(T->lchild); 
			Get_PreSeq(T->rchild);
		}
	}
}