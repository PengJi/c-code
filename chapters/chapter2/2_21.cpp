typedef struct{
	ElemType elem[MaxSize];
	int length;
}SqList;
void ReverseSq(SqList &L){
	//顺序表就地逆置
	//对于表的前半部分，将与其表的后半部分的对应元素进行交换
	ElemType temp;
	for(int i=0;i<L.length/2;i++){
		temp=L.elem[i];
		L.elem[i]=L.elem[L.length-i-1];
		L.elem[L.length-i-1]=temp;
	}
}