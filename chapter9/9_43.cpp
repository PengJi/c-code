Status TrieTree_Delete_Key(TrieTree &T,StringType key){
	//��Trie ��T ��ɾ���ַ���key
	p=T;i=1;
	while(p&&p->kind==BRANCH&&i<=key[0]){ //���Ҵ�ɾ��Ԫ��
		last=p;
		p=p->bh.ptr[ord(key[i])];
		i++;
	}
	if(p&&p->kind==LEAF&&p->lf.k=key){ //�ҵ��˴�ɾ��Ԫ��
		last->bh.ptr[ord(key[i-1])]=NULL;
		free(p);
		return OK;
	}
	else 
		return ERROR; 
}