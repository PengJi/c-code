void Count_Sort(int a[ ],int n){
	//¼ÆÊıÅÅĞòËã·¨
	int c[MAXSIZE];
	for(i=0;i<n;i++){
		for(j=0,count=0;j<n;j++)
			if(a[j]<a[i]) 
				count++:
			c[i]=count;
	}
	for(i=0;i<n;i++){
		min=0;
		for(j=0;j<n;j++)
			if(c[j]<c[min]) 
				min=j;
			a[i]<->a[min]; 
			c[min]=INFINITY; 
	}
}