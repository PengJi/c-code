int c,k;
void Get_PreSeq(Bitree T){
	//����������Ϊk �Ľ���ֵ
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