typedef struct {
	LNode *h; //h ָ����СԪ��
	LNode *t; //t ָ���ϴβ��ҵĽ��
} CSList;
LNode *Search_CSList(CSList &L,int key){
	//������ѭ������洢�ṹ�ϵĲ����㷨,�ٶ�ÿ�β��Ҷ��ɹ�
	if(L.t->data==key) 
		return L.t;
	else if(L.t->data>key)
		for(p=L.h,i=1;p->data!=key;p=p->next,i++);
	else
		for(p=L.t,i=L.tpos;p->data!=key;p=p->next,i++);
	L.t=p;
	return p;
}