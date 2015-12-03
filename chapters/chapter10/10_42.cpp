typedef struct {
	int gt; 
	int lt; 
} place;
int Get_Mid(int a[ ],int n){
	//求一个序列的中值记录的位置
	place b[MAXSIZE];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(a[j]>a[i]) 
				b[i].gt++;
			else if(a[j]<a[i]) 
				b[i].lt++;
		}
		mid=0;
		min_dif=abs(b[0].gt-b[0].lt);
		for(i=0;i<n;i++)
			if(abs(b[i].gt-b[i].lt)<min_dif) 
				mid=i;
			return mid;
}