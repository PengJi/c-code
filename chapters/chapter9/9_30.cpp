typedef struct {
	DLNode *pre;
	int data;
	DLNode *next;
} DLNode;
typedef struct {
	DLNode *sp;
	int length;
} DSList; //�����ҵ�˫��ѭ����������
DLNode *Search_DSList(DSList &L,int key){
	//������˫��ѭ������洢�ṹ�ϵĲ����㷨,�ٶ�ÿ�β��Ҷ��ɹ�
	p=L.sp;
	if(p->data>key){
		while(p->data>key) 
			p=p->pre;
		L.sp=p;
	}
	else if(p->data<key){
		while(p->data<key)
			p=p->next;
		L.sp=p;
	}
	return p;
}