typedef struct{
	ElemType elem[MaxSize];
	int length;
}SqList;
void ReverseSq(SqList &L){
	//˳���͵�����
	//���ڱ��ǰ�벿�֣��������ĺ�벿�ֵĶ�ӦԪ�ؽ��н���
	ElemType temp;
	for(int i=0;i<L.length/2;i++){
		temp=L.elem[i];
		L.elem[i]=L.elem[L.length-i-1];
		L.elem[L.length-i-1]=temp;
	}
}