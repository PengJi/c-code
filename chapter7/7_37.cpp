int maxlen,path[MAXSIZE]; //����path ���ڴ洢��ǰ·��
int mlp[MAXSIZE]; //����mlp ���ڴ洢�ѷ��ֵ��·��
void Get_Longest_Path(ALGraph G){
	//��һ�������޻�ͼ�����·��
	maxlen=0;
	FindIndegree(G,indegree);
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++) 
			visited[j]=0;
		if(!indegree[i]) DFS(G,i,0);
	}
	printf("Longest Path:");
	for(i=0;mlp[i];i++) 
		printf("%d",mlp[i]);
}
void DFS(ALGraph G,int i,int len){
	visited[i]=1;
	path[len]=i;
	if(len>maxlen&&!G.vertices[i].firstarc) {
		for(j=0;j<=len;j++) 
			mlp[j]=path[j]; 
		maxlen=len;
	}
	else{
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			j=p->adjvex;
			if(!visited[j]) 
				DFS(G,j,len+1);
		}
	}
	path[i]=0;
	visited[i]=0;
}
