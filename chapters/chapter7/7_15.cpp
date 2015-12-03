Status Insert_Vex(MGraph &G,char v){
	//邻接矩阵表示的图G中插入v
	if((G.vexnum+1)>MAX_VERTEX_NUM)
		return INFEASIBLE;
	G.vexx[++G.vexnum]=v;
	return OK;
}
Status Insert_Arc(MGraph &G,char v,char w){
	//邻接矩阵表示的图G中插入边(v,w)
	if((i=LocateVex(G,v))<0)
		return ERROR;
	if((j=LocateVex(G,w))<0)
		return ERROR;
	if(i==j)
		return ERROR;
	if(!G.arcs[i][j].adj){
		G.arcs[i][j].adj=1;
		G.arcnum++;
	}
	return OK;
}
Status Delete_Vex(MGraph &G,char v){
	//邻接矩阵表示的图G中删除顶点v
	n=G.vexnum;
	if((m=LocateVex(G,v))<0)
		return ERROR;
	G.vexs[m]<>G.vexs[n];//将待删除顶点交换到最后一个顶点
	for(i=0;i<n;i++){
		G.arcs[i][m]=G.arcs[i][n];
		G.arcs[m][i]=G.arcs[n][i];
	}
	G.arcs[m][m].adj=0;
	G.vexnum--;
	return OK;
}
Status Delete_Arc(MGraph &G,char v,char w){
	//邻接矩阵表示的图G上删除边(v,w)
	if((i=LocateVex(G,v))<0)
		return ERROR;
	if((j=LocateVex(G,w))<0)
		return ERROR;
	if(G.arcs[i][j].adj){
		G.arcs[i][j].adj=0;
		G.arcnum--;
	}
	return OK;
}