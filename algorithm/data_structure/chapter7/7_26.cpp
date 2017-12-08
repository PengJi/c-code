Status TopoNo(ALGraph G){
	//对无环有向图的顶点进行编号，使其邻接矩阵为下三角
	int new[MAXSIZE],indegree[MAXSIZE];
	n=G.vexnum;
	FindInDegree(G,indegree);
	InitStack(S);
	for(i=1;i<G.vexnum;i++)
		if(!indegree[i])
			Push(S,i);
	count=0;
	while(!StackEmpty(S)){
		Pop(S,i);
		new[i]=n--;
		count++;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			k=p->adjvex;
			if(!(--indegree[k]))
				Push(S,k);
		}
	}
	if(count<G.vexnum)
		return ERROR;
	for(i=1;i<=n;i+++)
		cout<<"Old No:"<<i<<" "<<"New No:"<<new[i]<<endl;
	return OK;
}