typedef struct{
	ElemType elel[length+1];
	int length;
}SqList;
int insertOrderList(SqList &va,ElemType x){
	//�ڷǵݼ���˳���va�в���Ԫ�أ���ʹ���Գ�Ϊ�����
	//�Ӻ���ǰ������ֱ����ǰ��Ԫ��va.elem[i]��ֵС��x�������y֮��
	int i;
	if(listSize>=va.length) return 0;
	for(i=va.length;i>0,x<va.elem[i-1];i--)
		va.elem[i]=va.elem[i-1];
	va.elem[i]=x;
	va.length++;
	return 1;
}