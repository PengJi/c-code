typedef struct {
	int low;
	int high;
}boundary; //�����е����½�����
void QSort_NotRecurve(int SQList &L){
	//��������ķǵݹ��㷨
	low=1;high=L.length;
	InitStack(S); //S ��Ԫ��Ϊboundary ����
	while(low<high&&!StackEmpty(S)){
		if(high-low>2){
			pivot=Partition(L,low,high);
			if(high-pivot>pivot-low){
				Push(S,{pivot+1,high}); 
				high=pivot-1;
			}
			else{
				Push(S,{low,pivot-1});
				low=pivot+1;
			}
		}
		else if(low<high&&high-low<3){
			Easy_Sort(L,low,high);
			low=high;
		}
		else{
			Pop(S,a); 
			low=a.low;
			high=a.high;
		}
	}
}
int Partition(SQList &L,int low,int high){
	//һ�˻��ֵ��㷨,��������ͬ
	L.r[0]=L.r[low];
	pivotkey=L.r[low].key;
	while(low<high){
		while(low<high&&L.r[high].key>=pivotkey)
			high--;
		L.r[low]=L.r[high];
		while(low<high&&L.r[low].key<=pivotkey)
			low++;
		L.r[high]=L.r[low];
	}
	L.r[low]=L.r[0];
	return low;
}
void Easy_Sort(SQList &L,int low,int high){
	//�Գ���С��3 �������н��бȽ�����
	if(high-low==1) //������ֻ������Ԫ��
		if(L.r[low].key>L.r[high].key) 
			L.r[low]<->L.r[high];
		else{
			if(L.r[low].key>L.r[low+1].key) 
				L.r[low]<->L.r[low+1];
			if(L.r[low+1].key>L.r[high].key) 
				L.r[low+1]<->L.r[high];
			if(L.r[low].key>L.r[low+1].key) 
				L.r[low]<->L.r[low+1];
		}
}