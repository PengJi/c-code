int path[MAXSIZE],visited[MAXSIZE];
int Find_All_Path(ALGrach G,int u,int v,int k=0){
	//������ͼG�ж���u��v֮������м�·��
	path[k]=u;
	visited[u]=1;
	if(u==v){
		cout<<"�ҵ�һ��·��"<<endl;
		for(i=1;path[i];i++)
			cout<<path[i];
	}else{
		for(p=G.vertices[u].firstarc;p;p=p->nextarc){
			l=p->adjvex;
			if(!visited[l])
				Find_All_Path(G,l,v,k+1);
		}
		visited[u]=0;
		path[k]=0;
	}
}