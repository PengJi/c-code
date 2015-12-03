void Print_Hash(HashTable H){
	//按第一个字母顺序输出Hash 表中的所有关键字,其中处理冲突采用线性探测开放定址法
	for(i=1;i<=26;i++)
		for(j=i;H.elem[j].key;j=(j+1)%hashsize[sizeindex]) 
			if(H(H.elem[j].key)==i) printf("%s\n",H.elem[j]);
}
int H(char *s){//求Hash 函数
	if(s) 
		return s[0]-96; 
	else return 0;
}