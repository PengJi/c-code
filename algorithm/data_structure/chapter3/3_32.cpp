void getFibQueue(int k,int n){
	//����ѭ�����д洢�ķƲ��������е�ǰn+1��
	InitDQueue(Q);//MAXSIZE=k
	for(i=0;i<k-1;i++){
		Q.base[i]=0;
	}
	for(i=k;i<=n;i++){
		m=j%k;
		sum=0;
		for(j=0;j<k;j++)
			sum+=Q.base[(m+j)%k];
		Q.base[m]=sum;
	}
}