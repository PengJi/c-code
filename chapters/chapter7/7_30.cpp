int visited[MAXSIZE];
int path[MAXSIZE];
int cycles[MAXSIZE][MAXSIZE];
int thiscycle[MAXSIZE];
int cycount=0;
void GetAllCycle(ALGraph G){
	//求有向图中所有的简单回路
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(v=0;v<G.vexnum;v++)
		if(!visited[v])
			DFS(G,v,0);
}
vodi DFS(ALGraph G,int v,int k){
	visited[v]=1;
	path[k]=v;
	for(p=G.verticws[v].firstarc;p;p=p->nextarc){
		w=p->adjvex;
		if(!visited[w])
			DFS(G,w.k+1);
		else{
			for(i=0;path[i]!=w;i++);
			for(j=0;path[i+j;i++])
				thiscycle[j]=path[i+j];
			if(!exist_cycle())
				cycles[cycount++]=thiscycle;
			for(i=0;i<G.vexnum;i++)
				thiscycle[i]=0;
		}
	}
	path[k]=0;
	visited[k]=0;
}
int exist_cycle(){
	//判断thiscycle数组中记录的回路在cycles的记录中是否已经存在
	int temp[MAXSIZE];
	for(i=0;i<cycount;i++){ 
		j=0;c=thiscycle&#0;; 
		for(k=0;cycles[i][k]!=c&&cycles[i][k]!=0;k++);
		if(cycles[i][k]){
			for(m=0;cycles[i][k+m];m++)
				temp[m]=cycles[i][k+m];
			for(n=0;n<k;n++,m++)
				temp[m]=cycles[i][n]; 
			if(!StrCompare(temp,thiscycle)) 
				return 1; 
			for(m=0;m<G.vexnum;m++) temp[m]=0; 
		}
	}
	return 0; 
}