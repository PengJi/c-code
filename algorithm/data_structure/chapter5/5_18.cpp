void rightShift(int A[n],int k){
	//������A��Ԫ��ѭ������kλ��ֻ��һ�������ռ�
	for(int i=1;i<k;i++){
		if(n%i==0&&k%i==0)
			p=i;
	}
	for(int i=0;i<p;i++){
		j=i;
		m=(i+n-k)%n;
		temp=A[i];
		while(m!=i){
			A[j]=A[m];
			j=m;
			m=(j+n-k)%n;
		}
		A[j]=temp;
	}
}