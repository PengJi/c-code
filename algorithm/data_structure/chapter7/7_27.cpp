int visited[MAXSIZE];
int exist_len_path(ALGraph G,int i,int j,int k){
	//�ж����ڽӱ�ʽ�洢������ͼG�Ķ���i��j�Ƿ���ڳ���Ϊk�ļ�·��
	if(i==j && k==0)
		return 1;
	else if(k>0){
		visited[i]=1;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			l=p->adjvex;
			if(!visited[l])
				if(exist_len_path(G,l,j,k-1))
					return 1;
		}
		visited[i]=0;
	}
	return 0;
}