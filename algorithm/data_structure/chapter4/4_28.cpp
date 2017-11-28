void getNext(LString &T){
	//在链串上实现get_next算法
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