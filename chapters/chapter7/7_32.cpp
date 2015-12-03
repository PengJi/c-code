void Forest_Prim(ALGraph G,int k,CSTree &T){
	//�Ӷ���k�𣬹����ڽӱ�ṹ����С����ɭ��T���ú����ֵ�����洢
	for(j=0;j<G.vexnum;j++){
		if(j1=k){
			closedge[j]={k,Max_int};
			for(p=G.vertices[j].firstarc;p=p->nextarc)
				if(p->adjvex==k)
					closedge[j].lowcost=p->cost;
		}
		closedge[k].lowcost=0;
		for(i=1;i<G.vexnum;i++){
			k=minimum(closedge);
			if(closedge[k].lowcost<Max_int){
				Addto_Forest(T,closedge[k].adjvex,k);
				closedge[k].lowcost=0;
				for(p=G.vertices[k].firstarc;p;p=p->nextarc)
					if(p->cost<closedge[p->adjvex].lowcost)
						closedge[p->adjvex]={k,p->cost};
			}
			else
				Forest_Prime(G,k);
		}
	}
}
void Addto_Forest(CSTree &T,int i,int j){
	//��ӱ�(i,j)��ӵ������ֵ������ʾ����T
	p=Locate(T,i);
	q=(CSTNode *) malloc(sizeof(CSTNode));
	q->data=j;
	if(!p){
		p=(CSTNode *) malloc (sizeof(CSTNode));
		p->data=i;
		for(r=T;r->nextsib;r=r->nextsib);
		r->nextsib=p;
		p->firstchild=q;
	}else if(!p->firstchild){
		p->firstchild=q;
	}else{
		for(r=p->firstchild;r->nextsib;r=r->nextsib);
		r->nextsib=q;
	}
}