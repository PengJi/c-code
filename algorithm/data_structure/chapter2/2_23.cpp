typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int listMerge(LinkList &A,LinkList &B){
	//合并单链表A和B为C，C中的元素是A和B元素间隔排列，使用A和B的存储空间
	//一次间隔插入A和B的元素，最后插入较长链表的元素
	//链表不带头结点
	if(!A && !B)
		return 0;
	LinkList p,q,C,r,t;
	p=A->next;
	q=B->next;
	C=A;
	while(p&&q){
		r=p->next;//保存指针
		p->next=q;//插入B的元素
		if(r){
			t=q->next;
			q->next=r;
		}
		p=r;
		q=t;
	}
	return 1;
}