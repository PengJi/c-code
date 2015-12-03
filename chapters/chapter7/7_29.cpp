int GetPathNum_Len(ALGraph G,int i,int j,int len){
	//求邻接矩阵方式存储的有向图G的顶点i到顶点j之间的长度为len的简单路径数目
	if(i==j &&  len==0)
		return 1;
	else if(len>0){
		sum=0;
		visited[i]=1;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			l=p->adjvex;
			if(!visited[l])
				sum+=GetPathNum_Len(G,l,j,len-1)
		}
		visited[i]=0;
	}
	return sum;
}