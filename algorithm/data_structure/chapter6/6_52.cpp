typedef struct{
	BTNode node;
	int layer;
} BTNRecord; //����������ڲ�εļ�¼����
int FanMao(Bitree T){
	//��һ�ö�������"��ï��"
	int countd; 
	InitQueue(Q); 
	EnQueue(Q,{T,0});
	while(!QueueEmpty(Q)){
		DeQueue(Q,r);
		count[r.layer]++;
		if(r.node->lchild) 
			EnQueue(Q,{r.node->lchild,r.layer+1});
		if(r.node->rchild) 
			EnQueue(Q,{r.node->rchild,r.layer+1});
	} 
	h=r.layer;
	for(maxn=count[0],i=1;count[i];i++)
		if(count[i]>maxn) 
			maxn=count[i];
	return h*maxn;
}