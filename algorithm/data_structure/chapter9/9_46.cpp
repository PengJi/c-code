Status Locate_Hash(HashTable H,int row,int col,KeyType key,int &k){
	//��������ֵ��Hash ���ʾ��ϡ�������ȷ��Ԫ��key ��λ��k
	h=2*(100*(row/10)+col/10); 
	while(H.elem[h].key&&!EQ(H.elem[h].key,key))
		h=(h+1)%20000;
	if(EQ(H.elem[h].key,key)) 
		k=h;
	else k=NULL;
}