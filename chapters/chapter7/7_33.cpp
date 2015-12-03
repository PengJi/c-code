typedef struct{
	int vex;//������
	int ecno;//�����������ͨ������
}VexInfo;
VexInfo vexs[MAXSIZE];//���������ͨ�����ŵ�����
void Init_VexInfo(VexInfo &vexs[],int vexnum){
	//��ʼ��
	for(i=0;i<vexnum;i++)
		vexs[i]={i,i};
}
int is_ec(VexInfo vexs[],int i,int j){
	//�ж϶���i�Ͷ���j�Ƿ�����ͬһ����ͨ����
	if(vexs[i].ecno == vexs[j].ecno)
		return 1;
	else
		return 0;
}
void merge_ec(VexInfo &vexs[],int ec1,int ec2){
	//�ϲ���ͨ����ec1��ec2
	for(i=0;vexs[i].vex;i++)
		if(vexs[i].ecno==ec2)
			vexs[i].ecno==ec1;
}
void MinSpanTree_Kruscal(Graph G,EdgeSetType &EdgeSet,CSTree &T){
	//��³˹������ͼ����С�������㷨
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
	//�ѱ�(i,j)��ӵ������ֵ��������T��
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