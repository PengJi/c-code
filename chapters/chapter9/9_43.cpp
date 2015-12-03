Status TrieTree_Delete_Key(TrieTree &T,StringType key){
	//ÔÚTrie Ê÷T ÖÐÉ¾³ý×Ö·û´®key
	p=T;i=1;
	while(p&&p->kind==BRANCH&&i<=key[0]){ //²éÕÒ´ýÉ¾³ýÔªËØ
		last=p;
		p=p->bh.ptr[ord(key[i])];
		i++;
	}
	if(p&&p->kind==LEAF&&p->lf.k=key){ //ÕÒµ½ÁË´ýÉ¾³ýÔªËØ
		last->bh.ptr[ord(key[i-1])]=NULL;
		free(p);
		return OK;
	}
	else 
		return ERROR; 
}