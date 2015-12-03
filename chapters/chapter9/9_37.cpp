Status BSTree_Delete_key(BiThrTree &T,int x){
	//在后继线索二叉排序树T 中删除元素x
	BTNode *pre,*ptr,*suc;//ptr 为x 所在结点,pre 和suc 分别指向ptr 的前驱和后继
	p=T;last=NULL; //last 始终指向当前结点p 的前一个(前驱)
	while(!p->ltag) 
		p=p->lchild; //找到中序起始元素
	while(p){
		if(p->data==x){ //找到了元素x 结点
			pre=last;
			ptr=p;
		}
		else if(last&&last->data==x) 
			suc=p; //找到了x 的后继
		if(p->rtag) 
			p=p->rtag;
		else{
			p=p->rchild;
			while(!p->ltag) 
				p=p->lchild;
		} //转到中序后继
		last=p;
	}
	if(!ptr) 
		return ERROR; //未找到待删结点
	Delete_BSTree(ptr); //删除x 结点
	if(pre&&pre->rtag)
		pre->rchild=suc; //修改线索
	return OK;
}
void Delete_BSTree(BiThrTree &T){
	//课本上给出的删除二叉排序树的子树T 的算法,按照线索二叉树的结构作了一些改动
	q=T;
	if(!T->ltag&&T->rtag) //结点无右子树,此时只需重接其左子树
		T=T->lchild;
	else if(T->ltag&&!T->rtag) //结点无左子树,此时只需重接其右子树
		T=T->rchild;
	else if(!T->ltag&&!T->rtag){ //结点既有左子树又有右子树
		p=T;r=T->lchild;
		while(!r->rtag){
			s=r;
			r=r->rchild; 
		}
		T->data=r->data; 
		if(s!=T)
			s->rchild=r->lchild;
		else 
			s->lchild=r->lchild; //重接r 的左子树到其双亲结点上
		q=r;
	}
	free(q); //删除结点
}