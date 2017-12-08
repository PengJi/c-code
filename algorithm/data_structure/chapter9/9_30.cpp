typedef struct {
	DLNode *pre;
	int data;
	DLNode *next;
} DLNode;
typedef struct {
	DLNode *sp;
	int length;
} DSList; //供查找的双向循环链表类型
DLNode *Search_DSList(DSList &L,int key){
	//在有序双向循环链表存储结构上的查找算法,假定每次查找都成功
	p=L.sp;
	if(p->data>key){
		while(p->data>key) 
			p=p->pre;
		L.sp=p;
	}
	else if(p->data<key){
		while(p->data<key)
			p=p->next;
		L.sp=p;
	}
	return p;
}