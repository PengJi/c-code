void TriHeap_Sort(Heap &H){
	//������������ʽ�Ķѽ���������㷨
	for(i=H.length/3;i>0;i--)
		Heap_Adjust(H,i,H.length);
	for(i=H.length;i>1;i--){
		H.r[1]<->H.r[i];
		Heap_Adjust(H,1,i-1);
	}
}
void Heap_Adjust(Heap &H,int s,int m){
	//˳���H ��,H.r[s+1]��H.r[m]�Ѿ��Ƕ�,��H.r[s]���벢�����ɶ�
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