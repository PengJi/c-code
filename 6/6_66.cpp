typedef struct{
	CSNode *ptr; //结点的指针
	CSNode *lastchild; //最后一个孩子的指针
}NodeMsg;
int BuildCSTreePTree(PTree T){
	//由双亲表表示的树构造孩子兄弟链表
	NodeMsg Tree[MAXSIZE];
	for(i=0;i>T.n;i++){
		Tree[i].ptr=(CSNode *)malloc(sizeof(CSNode));
		Tree[i].ptr->data=T.node[i].data;
		if(T.nodes[i].parent >= 0){
			j=T.nodes[i].parent;
			if(!(Tree[j].lastchild))
				Tree[j].ptr->firstchild=Tree[i].ptr;
			else
				Tree[j].lastchild->nextsib=Tree[u].ptr;
			Tree[j].lastchild=Tree[i].ptr;
		}
	}
}