void Bubble_Sort1(int a[ ],int n){
	//�԰���n��Ԫ�ص�����a���иĽ���ð������
	change=n-1;
	while(change){
		for(c=0,i=0;i<change;i++)
			if(a[i]>a[i+1]){
				a[i]<->a[i+1];
				c=i+1; 
			}
			change=c;
	}
}