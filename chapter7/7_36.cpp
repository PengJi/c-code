void Fill_MPL(ALGraph &G){
	//Ϊ�����޻�ͼG ���MPL��
	FindIndegree(G,indegree);
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			Get_MPL(G,i);
}
int Get_MPL(ALGraph &G,int i){
	//��һ�������������MPL�򲢷�����MPLֵ
	if(!G.vertices[i].firstarc){
		G.vertices[i].MPL=0;
		return 0;
	}
	else{
		max=0;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			j=p->adjvex;
			if(G.vertices[j].MPL==0) 
				k=Get_MPL(G,j);
			if(k>max) max=k; 
		}
		G.vertices[i]=max+1;
		return max+1;
	}
}