void insertStr(LString &t,LString &s,char c){
	//�����洢�Ĵ�����s����t�е�c�ַ�����
	p=t.head->next;
	while(p&&!(findChar(p,c)))
		p=p->next;
	if(!p){//û�ҵ��ַ�
		t.tail->next=s.head;
		t.tail=s.tail;
	}else{
		q=p->next;
		r=(Chunk*)malloc(sizeof(Chunk));
		for(j=i;j<ChunkSize;j++){
			r->ch[j]=p->ch[j];
			p->ch[j]='@';
		}
		p->next=s.head;
		s.tail->next=t;
		r->next=q;
	}
	t.len += s.len;
	s.len=0;
}
int findChar(Chunk *p,char c){
	for(i=0;i<ChunkSize&&p->ch[i]!=c;i++);
	if(i==ChunkSize)
		return 0;
	else
		return i+1;
}