void trainRearrange(char *train){
	//扫描队列，把S从头端出入队列，把H从尾端插入队列，然后从头端输出队列，则总的顺序为PSH
	t=train;
	InitDQueue(Q);
	while(*r){
		if(*r=='P'){
			printf('E');
			printf('D');
			printf(*r);//直接输出P
		}else if(*r=='S'){
			printf('E');
			EnDQueue(Q,*r,0);//从队首插入S
		}else{
			printf('A');
			EnDQueue(Q,*r,1);//从队尾插入H
		}
		r=r+1;
	}
	while(!DQueueEmpty(Q)){//从队首依次输出元素
		printf("D");
		DeDQeue("Q");
	}
}