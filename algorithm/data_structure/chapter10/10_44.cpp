void Enum_Sort(int a[ ],int n){
	//�Թؼ���ֻ��ȡv ��w ֮���������������н�������
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