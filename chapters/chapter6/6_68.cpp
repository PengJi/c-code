int CreateCSTreeDegree(char node[],int degree[]){
	//由结点的层序序列和各结点的度构建树的孩子兄弟链表
	CSNode *ptr[MAXSIZE];
	ptr[0]=(CSNode *)malloc(sizeof(CSNode));
	i=0;
	k=1;
	while(node[i]){
		ptr[i]->data=node[i];
		d=degeree[i];
		if(d){
			ptr[k]=(CSNode*)malloc(sizeof(CSNode));
			ptr[i]->firstchild=ptr[k];
			for(j=2;j<=d;j++){
				ptr[k]=(CSNode*)malloc(sizeof(CSNode));
				ptr[k-1]->nextsib=ptr[k];
				k++;
			}
			ptr[k-1]->nextsib=NULL;
		}
		i++;
	}
}