typedef struct{
	ElemType elem[MaxSize];
	int length;
}LNode,*LinkList;
int delectSame(LNode &A,LNode &B,LNode &C){
	//ɾ��A���е���B��C�ж����ڵ�Ԫ��
	//����B��C���ҳ�B��C�ж����ڵ�Ԫ�أ� ��ɾ��A����ͬ��Ԫ��
	int i=0,j=0,k=0,m=0;
	Elemtype same;
	while(i<A.length && j<B.length && C.length){
		if(B.elem[j]<C.elem[k])
			j++;
		else if(B.elem[j]>C.elem[k])
			k++;
		else{//�ҵ���ͬԪ��
			same=B.elem[j];
			while(B.elem[j]==same) j++;
			while(C.elem[k]==same) k++;
			while(i<A.length && A.elem[i]<same)
				A.elem[m++]=A.elem[i++];//mΪ��ǰ�ظ�Ԫ�ص�λ�ã���������һ��ѭ��ʱ�滻
			while(i<A.length&&A.elem[i]==same)
				i++;//������ͬ��Ԫ��
		}
	}
	while(i<A.length)
		A.elem[m++]=A.elem[i++];
	A.length=m;
}