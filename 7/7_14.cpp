Status Build_AdjList(ALGraph &G){
	//输入有向图的顶点数，边数，顶点信息和边的信息尽力邻接表
	InitALGraph(G);
	cin>>v;
	if(v<0)
		return ERROR;
	G.vexnum=v;
	cin>>a;
	if(a<0)
		return ERROR;
	G.arcnum=a;
	for(m=0;m<v;m++){
		G.vertices[m].data=getchar();
	}
	for(m=1;m<=a;m++){
		t=getchar();
		h=getchar();
		if((i=LocateVex(G,t))<0)
			return ERROR;
		if((j=LocateVex(G,h))<0)
			return ERROR;
		if(!G.vertices[i].firstarc)
			G.vertices[i].firstarc=p;
		else{
			for(q=G.vertices[i].firstarc;q->nextarc;q=q->nextarc);
			q->nextarc=p;
		}
		p->adjvex=j;
		p->nextarc=NULL;
	}
	return OK;
}