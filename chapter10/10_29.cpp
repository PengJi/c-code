void OE_Sort(int a[ ],int n){
	//��ż���������㷨
	change=1;
	while(change){
		change=0;
		for(i=1;i<n-1;i+=2)
			if(a[i]>a[i+1]){
				a[i]<->a[i+1];
				change=1;
			}
			for(i=0;i<n-1;i+=2)
				if(a[i]>a[i+1]){
					a[i]<->a[i+1];
					change=1;
				}
	}
}
