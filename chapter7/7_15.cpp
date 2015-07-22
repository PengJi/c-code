Status Insert_Vex(MGraph &G,char v){
	//�ڽӾ����ʾ��ͼG�в���v
	if((G.vexnum+1)>MAX_VERTEX_NUM)
		return INFEASIBLE;
	G.vexx[++G.vexnum]=v;
	return OK;
}
Status Insert_Arc(MGraph &G,char v,char w){
	//�ڽӾ����ʾ��ͼG�в����(v,w)
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
	//�ڽӾ����ʾ��ͼG��ɾ������v
	n=G.vexnum;
	if((m=LocateVex(G,v))<0)
		return ERROR;
	G.vexs[m]<>G.vexs[n];//����ɾ�����㽻�������һ������
	for(i=0;i<n;i++){
		G.arcs[i][m]=G.arcs[i][n];
		G.arcs[m][i]=G.arcs[n][i];
	}
	G.arcs[m][m].adj=0;
	G.vexnum--;
	return OK;
}
Status Delete_Arc(MGraph &G,char v,char w){
	//�ڽӾ����ʾ��ͼG��ɾ����(v,w)
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