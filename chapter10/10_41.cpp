void Hash_Sort(int a[ ]){
	//对1000 个关键字为四位整数的记录进行排序
	int b[10000];
	for(i=0;i<1000;i++){
		for(j=a[i];b[j];j=(j+1)%10000);
		b[j]=a[i];
	}
	for(i=0,j=0;i<1000;j++)
		if(b[j]){
			for(x=b[j],k=j;b[k];k=(k+1)%10000)
				if(b[k]==x){
					a[i++]=x;
					b[k]=0;
				}
		}
}