void Divide(int a[ ],int n){
	//������a������ֵΪ���ļ�¼�����Ǹ��ļ�¼֮ǰ
	low=0;high=n-1;
	while(low<high){
		while(low<high&&a[high]>=0) 
			high--;
		a[low]<->a[high];
		while(low<high&&a[low]<0) 
			low++;
		a[low]<->a[high];
	}
}