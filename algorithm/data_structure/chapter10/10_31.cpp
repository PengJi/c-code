void Divide(int a[ ],int n){
	//把数组a中所有值为负的记录调到非负的记录之前
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