int Pass_ALGraph(ALGraph G){
	//�ڽӱ�洢������ͼ�Ƿ�ɴ���
	for(x=0;x<G.vexnum;x++)
		for(p=G.vertices[x].firstarc;p;p=p->nextarc){
			y=p->adjvex;
			for(q=G.vertices[y].firstarc;q;q=q->nextarc){
				z=q->adjvex;
				if(z!=x && !is_adj(G,x,z))
					return 0
			}
		}
}
int is_adj(ALGraph G,int m,int n){
	//�ж�����ͼG���Ƿ���ڱ�(m,n)
	for(p=G.vertices[m].firstarc;p;p=p->nextarc)
		if(p->adjvex==n)
			return 1;
	return 0;
}