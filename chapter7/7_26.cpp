Status TopoNo(ALGraph G){
	//���޻�����ͼ�Ķ�����б�ţ�ʹ���ڽӾ���Ϊ������
	int new[MAXSIZE],indegree[MAXSIZE];
	n=G.vexnum;
	FindInDegree(G,indegree);
	InitStack(S);
	for(i=1;i<G.vexnum;i++)
		if(!indegree[i])
			Push(S,i);
	count=0;
	while(!StackEmpty(S)){
		Pop(S,i);
		new[i]=n--;
		count++;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			k=p->adjvex;
			if(!(--indegree[k]))
				Push(S,k);
		}
	}
	if(count<G.vexnum)
		return ERROR;
	for(i=1;i<=n;i+++)
		cout<<"Old No:"<<i<<" "<<"New No:"<<new[i]<<endl;
	return OK;
}