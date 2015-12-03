int enDQueue(DQueue &Q,int x){
	//输出受限的双端队列的插入
	if((Q.rear+1)%MAXSIZE==Q.front)
		return 0;//队列满
	aver=(Q.base[Q.rear+1]+Q.base[Q.front])/2;
	if(x>=aver){//插入队尾
		Q.base[Q.rear]=x;
		Q.rear=(Q.rear+1)%MAXSIZE;
	}else{//插入队首
		Q.front=(Q.front-1)%MAXSIZE;
		Q.base[Q.front]=x;
	}
	return 1;
}