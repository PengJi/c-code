void getNext(LString &T){
	//��������ʵ��get_next�㷨
	p=T->succ;
	p->next=T;
	q=T;
	while(p->succ){
		if(q==T||p->data==q->data){
			p=p->succ;
			q=q->succ;
			p->next=q;
		}else{
			q=q->next;
		}
	}
}