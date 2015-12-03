void Bubble_Sort1(int a[ ],int n){
	//对包含n个元素的数组a进行改进的冒泡排序
	change=n-1;
	while(change){
		for(c=0,i=0;i<change;i++)
			if(a[i]>a[i+1]){
				a[i]<->a[i+1];
				c=i+1; 
			}
			change=c;
	}
}