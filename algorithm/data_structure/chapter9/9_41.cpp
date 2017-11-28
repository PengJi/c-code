typedef struct {
	enum {LEAF,BRANCH} tag; //结点类型标识
	int keynum;
	BPLink parent; //双亲指针
	int key[MAXCHILD]; //关键字
	union {
		BPLink child[MAXCHILD];//非叶结点的孩子指针
		struct {
			rectype *info[MAXCHILD];//叶子结点的信息指针
			BPNode *next; //指向下一个叶子结点的链接
		} leaf;
	}
} BPNode,*BPLink,*BPTree;//B+树及其结点类型
Status BPTree_Search(BPTree T,int key,BPNode *ptr,int pos){
	//B+树中按关键字随机查找的算法,返回包含关键字的叶子结点的指针ptr 以及关键字在叶子结点中的位置pos
	p=T;
	while(p.tag==BRANCH){
		//沿分支向下查找
		for(i=0;i<p->keynum&&key>p->key[i];i++); //确定关键字所在子树
		if(i==p->keynum) 
			return ERROR; 
		p=p->child[i];
	}
	for(i=0;i<p->keynum&&key!=p->key[i];i++); //在叶子结点中查找
	if(i==p->keynum) 
		return ERROR; 
	ptr=p;pos=i;
	return OK;
}