typedef struct{
	ElemType elem[MaxSize];
	int length;
}LNode,*LinkList;
int splitList(LNode A,LNode B,LNode C){
	//将递增有序的线性表A和B中相同的元素存入C中
	//遍历A与B，当找到相同的元素时，便存入C
	int i=1,j=1,k=0;
	while(A.elem[i]&&B.elem[j]){
		if(A.elem[i]<B.elem[j])
			i++;
		if(A.elem[i]>B.elem[j])
			j++;
		if(A.elem[i]==B.elem[j]){//找到相同元素
			C.elem[++k]=A.elem[i];//存入C
			i++;
			j++;
		}
	}
}