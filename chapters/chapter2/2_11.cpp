typedef struct{
	ElemType elel[length+1];
	int length;
}SqList;
int insertOrderList(SqList &va,ElemType x){
	//在非递减的顺序表va中插入元素，并使其仍成为有序表
	//从后往前遍历，直到当前的元素va.elem[i]的值小于x，则插入y之后
	int i;
	if(listSize>=va.length) return 0;
	for(i=va.length;i>0,x<va.elem[i-1];i--)
		va.elem[i]=va.elem[i-1];
	va.elem[i]=x;
	va.length++;
	return 1;
}