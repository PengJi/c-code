int visited[MAXSIZE]; 
int exist_path_DFS(ALGraph G,int i,int j){
	//��������ж�����ͼG �ж���i ������j �Ƿ���·��,���򷵻�1,���򷵻�0
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