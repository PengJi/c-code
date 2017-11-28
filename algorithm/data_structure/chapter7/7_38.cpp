void NiBoLan_DAG(ALGraph G){
	//��������޻�ͼ��ʽ��ʾ�ı��ʽ���沨��ʽ
	FindIndegree(G,indegree);
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			r=i;
	PrintNiBoLan_DAG(G,i);
}
void PrintNiBoLan_DAG(ALGraph G,int i){
	//��ӡ����Զ���iΪ���ı��ʽ���沨��ʽ
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
