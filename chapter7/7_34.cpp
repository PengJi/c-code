Status TopoSeq(ALGraph G,int newOrder[]){
	//无环有向图的结点重新编号
	int indegree[MAXSIZE];
	FindIndegree(G,indegree);
	Initstack(S);
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i])
			Push(S,i);
	count=0;
	while(!stackempty(S)){
		Pop(S,i);
		newOrder[i]=++count;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			k=p->adjvex;
			if(!(--indegree[k]))
				Push(S,k);
		}
	}
	if(count<G.vexnum)
		return ERROR;
	return OK;
}