int Pass_MGraph(MGraph G){
	//判断邻接矩阵存储的有向图是否可传递
	for(x=0;x<G.vexnum;x++)
		for(y=0;y<G.vexnum;y++)
			if(G.arcs[x][y]){
				for(z=0;z<G.vexnum;z++)
					if(z!=x && G.arcs[y][z] && !G.arcs[x][z])
						return 0;
			}
	return 1;
}