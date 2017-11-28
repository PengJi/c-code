typedef struct{
	ElemType base[MaxSize];
	int front;
	int rear;
	int tag;
}DQueue;
//�����ʱ�����front=rear������tag=1 ����
//������ʱ�����front=rear������tag=0 �ӿ�
int enDQueue(DQueue &q,int x){
	//��tag��ѭ���������
	if(q.front==q.rear && q.tag==1)//����
		return 0;
	q.rear=(q.rear+1)%MaxSize;
	q.base[q.rear]=x;
	if(q.front==q.rear)
		q.tag=1;
	return 1;
}
int deDQueue(DQueue &q,int &x){
	if(q.front==q.rear && q.tag==0)//�ӿ�
		return 0;
	x=q.base[q.front];
	q.front=(q.front+1)%MaxSize;
	if(q.front==q.rear)
		q.tag=0;
	return 1;
}