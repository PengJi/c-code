int enDQueue(DQueue &Q,int x){
	//������޵�˫�˶��еĲ���
	if((Q.rear+1)%MAXSIZE==Q.front)
		return 0;//������
	aver=(Q.base[Q.rear+1]+Q.base[Q.front])/2;
	if(x>=aver){//�����β
		Q.base[Q.rear]=x;
		Q.rear=(Q.rear+1)%MAXSIZE;
	}else{//�������
		Q.front=(Q.front-1)%MAXSIZE;
		Q.base[Q.front]=x;
	}
	return 1;
}