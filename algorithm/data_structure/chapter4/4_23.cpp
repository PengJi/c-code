int LStringPalindrome(LString L){
	//�ж��Կ����ṹ�洢�Ĵ��Ƿ�Ϊ����
	InitStack(S);
	p=S.head;
	int i=0,l=1;
	for(k=1;k<=S.len;k++){
		if(k<=S.len/2)
			push(S,p->ch[i]);
		else if(k>(S.len+1)/2){
			pop(S,c);
			if(p->ch[i]!=c)
				return 0;
		}
		if(++i=ChunkSize){
			p=p->next;
			i=0;
		}
	}
	return 1;
}