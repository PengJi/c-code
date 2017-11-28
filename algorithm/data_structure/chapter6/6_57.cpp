Bitree PostOrder_Next(Bitree p){
	//在后序后继线索二叉树中查找结点p 的后序后继,并返回指针
	if(p->rtag) 
		return p->rchild; //p 有后继线索
	else if(!p->parent) 
		return NULL; //p 是根结点
	else if(p==p->parent->rchild) 
		return p->parent; //p 是右孩子
	else if(p==p->parent->lchild&&p->parent->rtag)
		return p->parent; //p 是左孩子且双亲没有右孩子
	else{ //p 是左孩子且双亲有右孩子
		q=p->parent->rchild;
		while(q->lchild||!q->rtag){
			if(q->lchild) q=q->lchild;
			else q=q->rchild;
		} //从p 的双亲的右孩子向下走到底
		return q;
	}
}