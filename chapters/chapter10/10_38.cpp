void LinkedList_Merge_Sort2(LinkedList &L){
	//初始归并段为最大有序子序列的归并排序,采用链表存储结构
	LNode *end[MAXSIZE]; //设立一个数组来存储各有序子序列的尾指针
	for(p=L->next->next,i=0;p;p=p->next) //求各有序子序列的尾指针
		if(!p->next||p->data>p->next->data) 
			end[i++]=p;
		while(end[0]->next){
			j=0;k=0; 
			for(p=L->next,e2=p;p->next;p=e2){
				e1=end[j];
				e2=end[j+1]; 
				if(e1->next) 
					LinkedList_Merge(L,p,e1,e2);
				end[k++]=e2;
				j+=2; 
			}
		}
}
void LinkedList_Merge(LinkedList &L,LNode *p,LNode *e1,LNode *e2){
	//对链表上的子序列进行归并
	q=p->next;
	r=e1->next;
	while(q!=e1->next&&r!=e2->next){
		if(q->data<r->data){
			p->next=q;
			p=q;
			q=q->next;
		}else{
			p->next=r;
			p=r;
			r=r->next;
		}
	}
	while(q!=e1->next){
		p->next=q;
		p=q;
		q=q->next;
	}
	while(r!=e2->next){
		p->next=r;
		p=r;
		r=r->next;
	}
}