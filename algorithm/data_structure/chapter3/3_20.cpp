typedef struct{
	int x;
	int y;
}coordinate;
int replaceColor(int g[m][n],int i,int j,int color){
	//�ѵ�(i,j)��������ĵ��û�Ϊcolor
	coordinate a;
	old=g[i][j];
	a.x=i;a.y=j;
	InitiQueue(Q);
	EnQueue(Q,a);
	while(!QueueEmpty(Q)){
		DeQueue(Q,a);
		x=a.x;
		y=a.y;
		if(x>1)
			if(g[x-1][y]==old){//�޸����ڵ����ɫ
				g[x-1][y]=color;
				a.x=x-1;a.y=y;
				EnQueue(Q,a);
			}
		if(y>1)
			if(g[x][y-1]==old){//�޸����ڵ����ɫ
				g[x][y-1]=color;
				a.x=x;a.y=y-1;
				EnQueue(Q,a);
			}
		if(x<m)
			if(g[x+1][y]==old){//�޸����ڵ����ɫ
				g[x+1][y]=color;
				a.x=x+1;a.y=y;
				EnQueue(Q,a);
			}
		if(y<n)
			if(g[x][y+1]==old){//�޸����ڵ����ɫ
				g[x][y+1]=color;
				a.x=x;a.y=y+1;
				EnQueue(Q,a);
			}
	}
	return 1;
}
