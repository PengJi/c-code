LStrNode* LIndexKMP(LString S,LString T,LStrNode *pos){
	//链串上实现KMP算法，返回匹配的子串指针
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