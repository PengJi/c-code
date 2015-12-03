typedef struct{
	char data;
	CSNode *ptr;
	CSNode *lastchild;
}NodeInfo;
int CreateCSTreeDuplet(CSTree &T){
	//输入二元组建立树的孩子兄弟链表
	NodeInfo Treed;
	n=1;
	k=0;
	if(getchar()!='^')
		return 0;
	if((c=getchar())=='^')
		T=NULL;
	Tree[0].ptr=(CSNode*)malloc(sizeof(CSNode));
	Tree[0].data=c;
	Tree[0].ptr->data=c;
	while((p=getchar())!='^' && (c=getchar())!='^'){
		Tree[n].ptr=(CSNode *)malloc(sizeof(CSNode));
		Tree[n].data=c;
		Tree[n].ptr->data=c;
		for(k=0;Tree[k].data!=p;k++);
		if(Tree[k].data!=p)
			return 0;
		r=Tree[k].ptr;
		if(!r->firstchild)
			r->firstchild=Tree[n].ptr;
		else
			Tree[k].lastchild -> nextsib=Tree[n].ptr;
		Tree[k].lastchild = Tree[n].ptr;
		n++;
	}
	return 1;
}