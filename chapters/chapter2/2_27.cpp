typedef struct{
	ElemType elem[MaxSize];
	int length;
}SeqList;
int seqListInterset(SeqList &A,SeqList &B){
	//���������������˳���A��B�Ľ����������A��
	int i=1,j=1,k=0;
	if(!A || !B)
		return 0;
	while(A.elem[i]&& B.elem[j]){
		if(A.elem[i]<B.elem[j])
			i++;
		else if(A.elem[i]>B.elem[j])
			j++;
		else if(A.elem[i]==B.elem[j] && A.elem[k]!=A.elem[i]){//��ͬԪ�أ���û�����
			A.elem[++k]=A.elem[i];
			i++;
			j++;
		}else{
			i++;
			j++;
		}
	}
	while(A.elem[k])
		A.elem[k++]=0;
	return 1;
}