void printOLMatrix(OLMatrix A){
	//用三元组输出以十字链表存储的矩阵
	for(i=0;i<A.mu;i++){
		if(A.rhead[i])
			for(p=A.rhead[i];p;p=p->right)
				cout<<i<<" "<<p->j<<" "<<p->e;
	}
}