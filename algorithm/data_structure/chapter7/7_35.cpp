int visited[MAXSIZE];
void Get_Root(ALGraph G){
	//求有向无环图的根
	for(v=0;v<G.vexnum;v++){
		for(w=0;w<G.vexnum;w++) visited[w]=0;
		DFS(G,v); 
		for(flag=1,w=0;w<G.vexnum;w++)
			if(!visited[w]) 
				flag=0; 
			if(flag) 
				printf("Found a root vertex:%d\n",v);
	}
}
void DFS(ALGraph G,int v){
	visited[v]=1;
	for(p=G.vertices[v].firstarc;p;p=p->nextarc){
		w=p->adjvex;
		if(!visited[w]) 
			DFS(G,w);
	}
}
