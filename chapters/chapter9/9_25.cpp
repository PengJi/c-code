int Search_Sq(SSTable ST,int key){
	//在有序表上顺序查找的算法,监视哨设在高下标端
	ST.elem[ST.length+1].key=key;
	for(i=1;ST.elem[i].key>key;i++);
	if(i>ST.length||ST.elem[i].key<key)
		return ERROR;
	return i;
}