void SL_Merge(int a[ ],int l1,int l2){
	//�ѳ��ȷֱ�Ϊl1,l2 ��l1^2<(l1+l2)���������������й鲢Ϊ��������
	start1=0;
	start2=l1;
	for(i=0;i<l1;i++){
		for(j=start2;j<l1+l2&&a[j]<a[start1+i];j++); 
		k=j-start2; 
		RSh(a,start1,j-1,k);
		start1+=k+1;
		start2=j;
	}
}
void RSh(int a[ ],int start,int end,int k){
	//��a[start]��a[end]֮���������ѭ������k λ
	len=end-start+1;
	for(i=1;i<=k;i++)
		if(len%i==0&&k%i==0) p=i;
		for(i=0;i<p;i++){
			j=start+i;
			l=start+(i+k)%len;temp=a[j];
			while(l!=start+i){
				a[j]=temp;
				temp=a[l];
				a[l]=a[j];
				j=l;
				l=start+(j-start+k)%len;
			}
			a[start+i]=temp;
		}
}
