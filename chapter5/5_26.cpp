void printOLMatrix(OLMatrix A){
	//����Ԫ�������ʮ������洢�ľ���
	for(i=0;i<A.mu;i++){
		if(A.rhead[i])
			for(p=A.rhead[i];p;p=p->right)
				cout<<i<<" "<<p->j<<" "<<p->e;
	}
}