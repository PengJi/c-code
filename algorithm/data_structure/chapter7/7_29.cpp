int GetPathNum_Len(ALGraph G,int i,int j,int len){
	//���ڽӾ���ʽ�洢������ͼG�Ķ���i������j֮��ĳ���Ϊlen�ļ�·����Ŀ
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