typedef enum {0,1,2,3,4,5,6,7,8,9} digit; //��λ������
typedef digit[3] num; //3 λ��Ȼ������,�����λ�洢�ڵ��±�,��λ�洢�ڸ��±�
void Enum_Radix_Sort(num a[ ],int n){
	//���ü���ʵ�ֻ�������,���йؼ���Ϊ3λ��Ȼ��,����n����Ȼ��
	int number,pos ;
	num c[MAXSIZE];
	for(j=0;j<3;j++){ //���ζԸ�λ,ʮλ�Ͱ�λ����
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