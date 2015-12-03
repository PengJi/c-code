int visited[MAXSIZE];
int finished[MAXSIZE];
int count;
void Get_SGraph(OLGraph G){
	//����ʮ������洢������ͼG��ǿ��ͨ����
	count=0;
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(v=0;v<G.vexnum;v++)
		if(!visited[v])
			DFS1(G,v);
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(i=G.vexnum-1;i>=0;i--){
		v=finished(i);
		if(!visited[v]){
			cout<<endl;
			DFS2(G,v);
		}
	}
}
void DFS1(OLGraph G,int v){
	//��һ��������ȱ���
	visited[v]=1;
	for(p=G.xlist[v].firstout;p;p=p->tlink){
		w=p->headvex;
		if(!visited[w])
			DFS1(G,w);
	}
	finished[++count] = v;
}
void DFS2(OLGraph G,int v){
	//�ڶ�������������ȱ����㷨
	visited[v]=1;
	cout<<v;
	for(p=G.xlist[v].firstin;p;p=p->hlink){
		w=p->tailvex;
		if(!visited[w])
			DFS2(G,w);
	}
}