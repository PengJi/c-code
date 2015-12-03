typedef struct{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
int mergeReverse(LinkList &A,LinkList &B){
	//将递增有序的单链表A和B合并为递减有序的链表C，使用A和B的空间
	//遍历A和B，按从小到大的顺达依次把元素插入C的头部
	if(!A || !B)
		return 0;
	LinkList pa,pb,p,q;
	LinkList pc;//pc指向新链表的头部
	pa=A->next;
	pb=B->next;
	while(pa || pb){
		if(pa->data<pb->data){
			pc=pa;//插入A的元素
			q=pa->next;
			pa->next=p;
			p=q;
		}else{
			pc=pb;//插入B的元素
			q=pb->next;
			pb->next=p;
			pb=q;
		}
		p=pc;
	}
	C=A;
	A->next=pc;
}