void Build_Heap(Heap &H,int n){
	//�ӵ��±굽���±�������뽨�ѵ��㷨
	for(i=2;i<n;i++){
		j=i;
		while(j!=1) {
			k=j/2;
			if(H.r[j].key>H.r[k].key)
				H.r[j]<->H.r[k];
			j=k;
		}
	}
}