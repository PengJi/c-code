int visited[MAXSIZE]; 
int exist_path_DFS(ALGraph G,int i,int j){
	//深度优先判断有向图G 中顶点i 到顶点j 是否有路径,是则返回1,否则返回0
	if(i==j) 
		return 1; 
	else{
		visited[i]=1;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			k=p->adjvex;
			if(!visited[k]&&exist_path(k,j)) 
				return 1;
		}
	}
}