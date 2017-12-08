void Bubble_Sort2(int a[ ],int n)
	//相邻两趟是反方向起泡的冒泡排序算法
	low=0;high=n-1; //冒泡的上下界
	change=1;
	while(low<high&&change){
		change=0;
		for(i=low;i<high;i++)
			if(a[i]>a[i+1]){
				a[i]<->a[i+1];
				change=1;
			}
			high--; 
			for(i=high;i>low;i--)
				if(a[i]<a[i-1]){
					a[i]<->a[i-1];
					change=1;
				}
				low++; 
	}
}