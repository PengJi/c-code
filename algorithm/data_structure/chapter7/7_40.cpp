int Evaluate_DAG(ALGraph G){
	//�������޻�ͼ��ʾ�ı��ʽ��ֵ
	FindIndegree(G,indegree);
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			r=i;
		return Evaluate_imp(G,i);
}
int Evaluate_imp(ALGraph G,int i){
	//���ӱ��ʽ��ֵ
	if(G.vertices[i].tag=NUM) 
		return G.vertices[i].value;
	else{
		p=G.vertices[i].firstarc;
		v1=Evaluate_imp(G,p->adjvex);
		v2=Evaluate_imp(G,p->nextarc->adjvex);
		return calculate(v1,G.vertices[i].optr,v2);
	}
}
