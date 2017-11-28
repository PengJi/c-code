typedef enum {0,1,2,3,4,5,6,7,8,9} digit; //个位数类型
typedef digit[3] num; //3 位自然数类型,假设低位存储在低下标,高位存储在高下标
void Enum_Radix_Sort(num a[ ],int n){
	//利用计数实现基数排序,其中关键字为3位自然数,共有n个自然数
	int number,pos ;
	num c[MAXSIZE];
	for(j=0;j<3;j++){ //依次对个位,十位和百位排序
		for(i=0;i<n;i++) 
			number[a[i][j]]++;
		for(pos[0]=0,i=1;i<n;i++)
			pos[i]=pos[i-1]+num[i];
		for(i=0;i<n;i++) 
			c[pos[a[i][j]]++]=a[i];
		for(i=0;i<n;i++)
			a[i]=c[i];
	}
}