typedef struct{
	ElemType base[MaxSize];
	int rear;
	int length;
}Queue;//�����ȵ�ѭ������
//����������length=MaxSize
int enQueue(Queue &Q,int x){
	//ѭ���������
	if(Q.length==MazSize)//����
		return 0;
	Q.rear=(Q.rear+1)%MaxSize;
	Q.base[Q.rear]=x;
	Q.length++;
	return 1;
}
int deQueue(Queue &Q,int &x){
	//ѭ�����г���
	if(Q.length==0)
		return 0;
	head=((Q.rear+MaxSize)-Q.length+1)%MaxSize;//��ͷ����λ��
	x=Q.base[head];
	Q.length--;
}