typedef *LNode[MAXSIZE] CHashTable; //����ַHash ������
Status Build_Hash(CHashTable &T,int m){
	//����һ��ؼ���,����Hash ��,��Ϊm,������ַ�������ͻ.
	if(m<1)
		return ERROR;
	T=malloc(m*sizeof(WORD)); 
	for(i=0;i<m;i++) T[i]=NULL;
	while((key=Inputkey())!=NULL){ 
		q=(LNode*)malloc(sizeof(LNode));
		q->data=key;q->next=NULL;
		n=H(key);
		if(!T[n]) 
			T[n]=q; //��Ϊ����ĵ�һ�����
		else{
			for(p=T[n];p->next;p=p->next);
			p->next=q; 
		}
	}
	return OK;
}