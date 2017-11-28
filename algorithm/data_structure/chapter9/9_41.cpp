typedef struct {
	enum {LEAF,BRANCH} tag; //������ͱ�ʶ
	int keynum;
	BPLink parent; //˫��ָ��
	int key[MAXCHILD]; //�ؼ���
	union {
		BPLink child[MAXCHILD];//��Ҷ���ĺ���ָ��
		struct {
			rectype *info[MAXCHILD];//Ҷ�ӽ�����Ϣָ��
			BPNode *next; //ָ����һ��Ҷ�ӽ�������
		} leaf;
	}
} BPNode,*BPLink,*BPTree;//B+������������
Status BPTree_Search(BPTree T,int key,BPNode *ptr,int pos){
	//B+���а��ؼ���������ҵ��㷨,���ذ����ؼ��ֵ�Ҷ�ӽ���ָ��ptr �Լ��ؼ�����Ҷ�ӽ���е�λ��pos
	p=T;
	while(p.tag==BRANCH){
		//�ط�֧���²���
		for(i=0;i<p->keynum&&key>p->key[i];i++); //ȷ���ؼ�����������
		if(i==p->keynum) 
			return ERROR; 
		p=p->child[i];
	}
	for(i=0;i<p->keynum&&key!=p->key[i];i++); //��Ҷ�ӽ���в���
	if(i==p->keynum) 
		return ERROR; 
	ptr=p;pos=i;
	return OK;
}