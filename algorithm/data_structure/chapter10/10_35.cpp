void TriHeap_Sort(Heap &H){
	//利用三叉树形式的堆进行排序的算法
	for(i=H.length/3;i>0;i--)
		Heap_Adjust(H,i,H.length);
	for(i=H.length;i>1;i--){
		H.r[1]<->H.r[i];
		Heap_Adjust(H,1,i-1);
	}
}
void Heap_Adjust(Heap &H,int s,int m){
	//顺序表H 中,H.r[s+1]到H.r[m]已经是堆,把H.r[s]插入并调整成堆
	rc=H.r[s];
	for(j=3*s-1;j<=m;j=3*j-1){
		if(j<m&&H.r[j].key<H.r[j+1].key) 
			j++;
		if(j<m&&H.r[j].key<H.r[j+1].key) 
			j++;
		H.r[s]=H.r[j];
		s=j;
	}
	H.r[s]=rc;
}