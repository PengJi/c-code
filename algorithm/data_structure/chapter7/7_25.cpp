void PathDFS(Graph &G,vexindex v){
	//������Ƚ���·������
	if(!OnCurrentPath[v]){
		OnCurrentPath[v]=TRUE;
		EnCurrentPath(v,CurrentPath);
		if(P(v)&&Q(CurrentPath))
			print(CurrentPath);
		else{
			w=FirstAdjVex(G,v);
			while(w){
				PathDFS(G,w);
				w=NextAdjVex(G,v,w);
			}
		}
		OnCurrentPath[v]=FALSE;
		DeCurrentPath(v,Current);
	}
}