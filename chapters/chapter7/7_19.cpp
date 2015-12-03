Status Build_AjdMulist(AMLGraph &G){
	//输入有向图的顶点数，边数，顶点信息和边的信息建立邻接多重表
	InitAMLGraph(G);
	cin>>v;
	if(v<0)
		return ERROR;
	G.vexnum=v;
	cin>>a;
	if(a<0)
		return ERROR;
	G.arcnum=a;
	for(m=0;m<v;m++)
		G.adjmulist[m].data=getchar();
	for(m=1;m<a;m++){
		t=getchar();
		h=getchar();
		if((i=LocateVex(G,t))<0)
			return ERROR;
		if((j=LocateVex(G,h))<0)
			return ERROR;
		p=(EBox*)malloc(sizeof(EBox));
		p->ivex=i;
		p->jvex=j;
		p->ilink=NULL;
		p->jlink=NULL;
		if(!G.adjmulist[i].firstedge)
			G.adjmulist[i].firstedge=p;
		else{
			q=G.adjmulist[i].firstedge;
			while(q){
				r=q;
				if(q->ivex==i)
					q=q->ilink;
				else
					q=q->jlink;
			}
			if(r->ivex==i)
				r->ilink=p;
			else
				r->jlink=p;
		}
		if(!G.adjmulist[j].firstedge)
			G.adjmulist[j].firstedge=p;
		else{
			q=G.adjmulist[i].firstedge;
			while(q){
				r=q;
				if(q->jvex==j)
					q=q->jlink;
				else
					q=q->ilink;
			}
			if(r->jvex==j)
				r->jlink=p;
			else 
				r->ilink=p;
		}

	}
	return OK;
}