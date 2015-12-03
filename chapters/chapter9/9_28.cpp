typedef struct {
	int maxkey;
	int firstloc;
} Index;
typedef struct {
	int *elem;
	int length;
	Index idx[MAXBLOCK];
	int blknum;
} IdxSqList;
int Search_IdxSeq(IdxSqList L,int key){
	//�ֿ����,���۰���ҷ�ȷ����¼���ڿ�,���ڲ���˳����ҷ�
	if(key>L.idx[L.blknum].maxkey) 
		return ERROR; //�������Ԫ��
	low=1;high=L.blknum;
	found=0;
	while(low<=high&&!found){
		mid=(low+high)/2;
		if(key<=L.idx[mid].maxkey&&key>L.idx[mid-1].maxkey)
			found=1;
		else if(key>L.idx[mid].maxkey)
			low=mid+1;
		else 
			high=mid-1;
	}
	i=L.idx[mid].firstloc; //����½�
	j=i+blksize-1; //����Ͻ�
	temp=L.elem[i-1]; //��������Ԫ��
	L.elem[i-1]=key; //���ü�����
	for(k=j;L.elem[k]!=key;k--); //˳�����
	L.elem[i-1]=temp; //�ָ�Ԫ��
	if(k<i) return ERROR; //δ�ҵ�
	return k;
}