void Merge_Sort(int a[ ],int n){
	//�鲢����ķǵݹ��㷨
	for(l=1;l<n;l*=2) 
		for(i=0;(2*i-1)*l<n;i++){
			start1=2*l*i;
			end1=start1+l-1;
			start2=end1+1;
			end2=(start2+l-1)>(n-1)?(n-1):(start2+l-1);
			Merge(a,start1,end1,start2,end2); 
		}
}
void Merge(int a[ ],int s1,int e1,int s2,int e2){
	//������������a[s1]��a[e1]��a[s2]��a[e2]�鲢Ϊ��������a[s1]��a[e2]
	int b[MAXSIZE]; //���������洢����b
	for(i=s1,j=s2,k=s1;i<=e1&&j<=e2;k++){
		if(a[i]<a[j]) 
			b[k]=a[i++];
		else 
			b[k]=a[j++];
	}
	while(i<=e1) 
		b[k++]=a[i++];
	while(j<=e2) 
		b[k++]=a[j++]; 
	for(i=s1;i<=e2;i++)
		a[i]=b[i];
}