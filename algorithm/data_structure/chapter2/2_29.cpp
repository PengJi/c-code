typedef struct{
	ElemType elem[MaxSize];
	int length;
}LNode,*LinkList;
int delectSame(LNode &A,LNode &B,LNode &C){
	//删除A表中的在B与C中都存在的元素
	//遍历B与C，找出B与C中都存在的元素， 再删除A中相同的元素
	int i=0,j=0,k=0,m=0;
	Elemtype same;
	while(i<A.length && j<B.length && C.length){
		if(B.elem[j]<C.elem[k])
			j++;
		else if(B.elem[j]>C.elem[k])
			k++;
		else{//找到相同元素
			same=B.elem[j];
			while(B.elem[j]==same) j++;
			while(C.elem[k]==same) k++;
			while(i<A.length && A.elem[i]<same)
				A.elem[m++]=A.elem[i++];//m为当前重复元素的位置，保留在下一次循环时替换
			while(i<A.length&&A.elem[i]==same)
				i++;//跳过相同的元素
		}
	}
	while(i<A.length)
		A.elem[m++]=A.elem[i++];
	A.length=m;
}