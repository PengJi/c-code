void trainRearrange(char *train){
	//ɨ����У���S��ͷ�˳�����У���H��β�˲�����У�Ȼ���ͷ��������У����ܵ�˳��ΪPSH
	t=train;
	InitDQueue(Q);
	while(*r){
		if(*r=='P'){
			printf('E');
			printf('D');
			printf(*r);//ֱ�����P
		}else if(*r=='S'){
			printf('E');
			EnDQueue(Q,*r,0);//�Ӷ��ײ���S
		}else{
			printf('A');
			EnDQueue(Q,*r,1);//�Ӷ�β����H
		}
		r=r+1;
	}
	while(!DQueueEmpty(Q)){//�Ӷ����������Ԫ��
		printf("D");
		DeDQeue("Q");
	}
}