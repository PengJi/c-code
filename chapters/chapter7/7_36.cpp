void Fill_MPL(ALGraph &G){
	//为有向无环图G 添加MPL域
	FindIndegree(G,indegree);
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			Get_MPL(G,i);
}
int Get_MPL(ALGraph &G,int i){
	//从一个顶点出发构建MPL域并返回其MPL值
	if(!G.vertices[i].firstarc){
		G.vertices[i].MPL=0;
		return 0;
	}
	else{
		max=0;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			j=p->adjvex;
			if(G.vertices[j].MPL==0) 
				k=Get_MPL(G,j);
			if(k>max) max=k; 
		}
		G.vertices[i]=max+1;
		return max+1;
	}
}