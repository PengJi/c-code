typedef *LNode[MAXSIZE] CHashTable; //链地址Hash 表类型
Status Build_Hash(CHashTable &T,int m){
	//输入一组关键字,建立Hash 表,表长为m,用链地址法处理冲突.
	if(m<1)
		return ERROR;
	T=malloc(m*sizeof(WORD)); 
	for(i=0;i<m;i++) T[i]=NULL;
	while((key=Inputkey())!=NULL){ 
		q=(LNode*)malloc(sizeof(LNode));
		q->data=key;q->next=NULL;
		n=H(key);
		if(!T[n]) 
			T[n]=q; //作为链表的第一个结点
		else{
			for(p=T[n];p->next;p=p->next);
			p->next=q; 
		}
	}
	return OK;
}