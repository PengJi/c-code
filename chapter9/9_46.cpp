Status Locate_Hash(HashTable H,int row,int col,KeyType key,int &k){
	//根据行列值在Hash 表表示的稀疏矩阵中确定元素key 的位置k
	h=2*(100*(row/10)+col/10); 
	while(H.elem[h].key&&!EQ(H.elem[h].key,key))
		h=(h+1)%20000;
	if(EQ(H.elem[h].key,key)) 
		k=h;
	else k=NULL;
}