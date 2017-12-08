void NiBoLan_DAG(ALGraph G){
	//输出由向无环图形式表示的表达式的逆波兰式
	FindIndegree(G,indegree);
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			r=i;
	PrintNiBoLan_DAG(G,i);
}
void PrintNiBoLan_DAG(ALGraph G,int i){
	//打印输出以顶点i为根的表达式的逆波兰式
	c=G.vertices[i].data;
	if(!G.vertices[i].firstarc) 
		printf("%c",c);
	else {
		p=G.vertices[i].firstarc;
		PrintNiBoLan_DAG(G,p->adjvex);
		PrintNiBoLan_DAG(G,p->nexarc->adjvex);
		printf("%c",c);
	}
}
