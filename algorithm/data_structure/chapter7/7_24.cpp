void STraverse_Nonrecursive(Graph G){
	//非递归遍历强连通图G
	int visited[MAXSIZE];
	InitStack(S);
	Push(S,GetVex(G,1));
	visit(1);
	visited=1;
	while(!StackEmpty(S)){
		while(Gettop(S,i) && i){
			j=FirstAdjVex(G,i);
			if(j&&!visited[j]){
				visit(j);
				visited[j]=1;
				Push(S,j);
			}
		}
		if(!StackEmpty(S)){
			Pop(S,j);
			Gettop(S,i);
			k=NextAdjVex(G,i,j);
			if(k&&!visited[k]){
				visit(k);
				visited[k]=1;
				Push(S,k);
			}
		}
	}
}