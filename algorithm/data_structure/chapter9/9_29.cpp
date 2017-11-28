typedef struct {
	LNode *h; //h 指向最小元素
	LNode *t; //t 指向上次查找的结点
} CSList;
LNode *Search_CSList(CSList &L,int key){
	//在有序单循环链表存储结构上的查找算法,假定每次查找都成功
	if(L.t->data==key) 
		return L.t;
	else if(L.t->data>key)
		for(p=L.h,i=1;p->data!=key;p=p->next,i++);
	else
		for(p=L.t,i=L.tpos;p->data!=key;p=p->next,i++);
	L.t=p;
	return p;
}