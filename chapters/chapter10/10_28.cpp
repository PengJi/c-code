void Bubble_Sort3(int a[ ],int n){
	//����һ����㷨���л���,ѭ������ֻ����һ��ð��
	int b[ 3 ]; //b[0]Ϊð�ݵ��½�,b[ 2 ]Ϊ�Ͻ�,b[1]����
	d=1;
	b[0]=0;
	b[ 2 ]=n-1; //d Ϊð�ݷ���ı�ʶ,1 Ϊ����,-1 Ϊ����
	change=1;
	while(b[0]<b[ 2 ]&&change){
		change=0;
		for(i=b[1-d];i!=b[1+d];i+=d)
			if((a[i]-a[i+d])*d>0){
				a[i]<->a[i+d];
				change=1;
			}
			b[1+d]-=d;
			d*=-1;
	}
}