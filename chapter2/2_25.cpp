typedef struct{
	ElemType elem[MaxSize];
	int length;
}LNode,*LinkList;
int splitList(LNode A,LNode B,LNode C){
	//��������������Ա�A��B����ͬ��Ԫ�ش���C��
	//����A��B�����ҵ���ͬ��Ԫ��ʱ�������C
	int i=1,j=1,k=0;
	while(A.elem[i]&&B.elem[j]){
		if(A.elem[i]<B.elem[j])
			i++;
		if(A.elem[i]>B.elem[j])
			j++;
		if(A.elem[i]==B.elem[j]){//�ҵ���ͬԪ��
			C.elem[++k]=A.elem[i];//����C
			i++;
			j++;
		}
	}
}