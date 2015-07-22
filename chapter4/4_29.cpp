LStrNode* LIndexKMP(LString S,LString T,LStrNode *pos){
	//������ʵ��KMP�㷨������ƥ����Ӵ�ָ��
	p=pos;
	q=T->succ;
	while(p&&q){
		if(q==T||p->chdata==q->chdata){
			p=p->succ;
			q=q->succ;
		}else{
			q=q->next;
		}
	}
	if(!q){
		for(i=1;i<StrLen(T);i++)
			p=p->next;
		return p;
	}
	return NULL;
}