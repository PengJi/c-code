typedef struct{
	int vex;//结点序号
	int ecno;//结点所属的连通分量号
}VexInfo;
VexInfo vexs[MAXSIZE];//结点所属连通分量号的数组
void Init_VexInfo(VexInfo &vexs[],int vexnum){
	//初始化
	for(i=0;i<vexnum;i++)
		vexs[i]={i,i};
}
int is_ec(VexInfo vexs[],int i,int j){
	//判断顶点i和顶点j是否属于同一个连通分量
	if(vexs[i].ecno == vexs[j].ecno)
		return 1;
	else
		return 0;
}
void merge_ec(VexInfo &vexs[],int ec1,int ec2){
	//合并连通分量ec1和ec2
	for(i=0;vexs[i].vex;i++)
		if(vexs[i].ecno==ec2)
			vexs[i].ecno==ec1;
}
void MinSpanTree_Kruscal(Graph G,EdgeSetType &EdgeSet,CSTree &T){
	//克鲁斯卡尔求图的最小生成树算法
	Init_VexInfo(vexs,G.vexnum);
	ecnum=G.vexnum;
	while(ecnum>1){
		GetMinEdge(EdgeSet,u,v);
		if(!is_ec(vexs,u,v)){
			Addto_CSTree(T,u,v);
			merge_ec(vexs,vexs[u].ecno,vexs[v].ecno);
			ecnum--;
		}
		DelMinEdge(EdgeSet,u,v);
	}
}
void Addto_CSTree(CSTree &T,int i,int j){
	//把边(i,j)添加到孩子兄弟链表的树T中
	p=Locate(T,i);
	q=(CSTNode *)malloc(sizeof(CSTNode));
	q->data=j;
	if(!p->firstchild)
		p->firstchild=q;
	else{
		for(r=p->firstchild;r->nextsib;r=r->nextsib);
		r->nextsib=q;
	}
}