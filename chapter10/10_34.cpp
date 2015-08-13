void Build_Heap(Heap &H,int n){
	//从低下标到高下标逐个插入建堆的算法
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