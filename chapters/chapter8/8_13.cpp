void Free_BT(Space &pav,Space p){
	//边界标志法的动态存储管理系统中回收空闲块p
	n=p->size;
	f=p+n-1;
	if((p-1)->tag && (f+1)->tag){
		p->tag=0;
		f->tag=0;
		f->uplink=p;
		if(!pav){
			p->llink=p;
			p->rlink=p;
		}else{
			q=pav->llink;
			p->llink=q;
			p->rlink=pav;
			q->rlink=p;
			pav->llink=p;
		}
		pav=p;
	}else if(!(p-1)->tag && (f+1)->tag){
		q=(p-1)->uplink;
		q->size += n;
		f->uplink=q;
		f->tag=0;
	}else if((p-1)->tag && (f+1) -> tag){
		q=f+1;
		s=q->llink;
		t=q->rlink;
		p->llink=s;
		p->rlink=t;
		s->rlink=p;
		t->llink=p;
		p->size += q->size;
		(q+q->size-1)->uplink=p;
		p->tag=0;
	}else{
		s=(p-1)->uplink;
		t=f+1;
		s->size += n+t->size;
		t->llink->rlink=t->rlink;
		t->rlink->llink=t->llink;
		(t+t->size-1) -> uplink=s;
	}
}