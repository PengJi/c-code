int exist_path_BFS(ALGraph G,int i,int j){
	//���ڹ�����������ж�ͼG�ж���i������j�Ƿ����·�������ڷ���1�����򷵻�0
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