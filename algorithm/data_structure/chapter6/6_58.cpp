Status Insert_BiThrTree(BiThrTree &T,BiThrTree &p,BiThrTree &x){
	//在中序线索二叉树T的结点p下插入子树x
	if(p->ltag){
		s=p->lchild; 
		p->ltag=Link;
		p->lchild=x;
		q=x;
		while(q->lchild&&!q->ltag) q=q->lchild;
		q->lchild=s; 
		x->rtag=Thread;
		x->rchild=p; 
	}
	else if(p->rtag){
		s=p->rchild; 
		p->rtag=Link;
		p->rchild=x;
		q=x;
		while(q->lchild&&!q->ltag) q=q->lchild;
		q->lchild=p; 
		x->rtag=Thread;
		x->rchild=s; 
	}
	else{
		s=p->lchild;t=s;
		while(t->lchild&&!t->ltag) t=t->lchild;
		u=t->lchild;
		p->lchild=x;
		x->rtag=Link;
		x->rchild=s;
		t->lchild=x;
		q=x;
		while(q->lchild&&!q->ltag) q=q->lchild;
		q->lchild=u; 
	}
	return OK;
}