void Insert_Sort(SqList &L){
	//监视哨设在高下标端的插入排序算法
	k=L.length;
	for(i=k-1;i;--i){
		if(L.r[i].key>L.r[i+1].key){
			L.r[k+1].key = L.r[i].key;//监视哨
			for(j=i+1;L.r[j].key>L.r[i].key;++j)
				L.r[j-1].key = L.r[j].key;
			L.r[j-1].key=L.r[k+1].key;
		}
	}
}