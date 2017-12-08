void TrieTree_Insert_Key(TrieTree &T,StringType key){
	// ÔÚTrie Ê÷T ÖĞ²åÈë×Ö·û´®key
	q=(TrieNode*)malloc(sizeof(TrieNode));
	q->kind=LEAF;
	q->lf.k=key; 
	klen=key[0];
	p=T;i=1;
	while(p&&i<=klen&&p->bh.ptr[ord(key[i])]){
		last=p;
		p=p->bh.ptr[ord(key[i])];
		i++;
	} 
	if(p->kind==BRANCH){
		p->bh.ptr[ord(key[i])]=q; 
		p->bh.num++;
	}
	else{
		r=(TrieNode*)malloc(sizeof(TrieNode)); 
		last->bh.ptr[ord(key[i-1])]=r; 
		r->kind=BRANCH;r->bh.num=2;
		r->bh.ptr[ord(key[i])]=q;
		r->bh.ptr[ord(p->lf.k[i])]=p; 
	}
}