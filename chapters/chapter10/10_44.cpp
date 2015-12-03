void Enum_Sort(int a[ ],int n){
	//对关键字只能取v 到w 之间任意整数的序列进行排序
	int number[w+1],pos[w+1];
	for(i=0;i<n;i++) 
		number[a[i]]++;
	for(pos[0]=0,i=1;i<n;i++)
		pos[i]=pos[i-1]+num[i]; 
	for(i=0;i<n;i++)
		c[pos[a[i]]++]=a[i];
	for(i=0;i<n;i++)
		a[i]=c[i];
}