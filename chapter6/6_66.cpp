typedef struct{
	CSNode *ptr; //����ָ��
	CSNode *lastchild; //���һ�����ӵ�ָ��
}NodeMsg;
int BuildCSTreePTree(PTree T){
	//��˫�ױ��ʾ�������캢���ֵ�����
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