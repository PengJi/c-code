int Search_Sq(SSTable ST,int key){
	//���������˳����ҵ��㷨,���������ڸ��±��
	ST.elem[ST.length+1].key=key;
	for(i=1;ST.elem[i].key>key;i++);
	if(i>ST.length||ST.elem[i].key<key)
		return ERROR;
	return i;
}