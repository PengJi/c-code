int Pass_MGraph(MGraph G){
	//�ж��ڽӾ���洢������ͼ�Ƿ�ɴ���
	for(x=0;x<G.vexnum;x++)
		for(y=0;y<G.vexnum;y++)
			if(G.arcs[x][y]){
				for(z=0;z<G.vexnum;z++)
					if(z!=x && G.arcs[y][z] && !G.arcs[x][z])
						return 0;
			}
	return 1;
}