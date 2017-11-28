int exist_path_BFS(ALGraph G,int i,int j){
	//基于广度优先搜索判断图G中顶点i到顶点j是否存在路径，存在返回1，否则返回0
	int visited[MAXSIZE];
	InitQueue(Q);
	EnQueue(Q,i);
	while(!QueueEmpty(Q)){
		DeQueue(Q,u);
		visited[u]=1;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			k=p->adjvex;
			if(k==j)
				return 1;
			if(!visited[k])
				EnQueue(Q,k);
		}
	}
	return 0;
}