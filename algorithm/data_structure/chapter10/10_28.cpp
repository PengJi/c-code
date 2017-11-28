void Bubble_Sort3(int a[ ],int n){
	//对上一题的算法进行化简,循环体中只包含一次冒泡
	int b[ 3 ]; //b[0]为冒泡的下界,b[ 2 ]为上界,b[1]无用
	d=1;
	b[0]=0;
	b[ 2 ]=n-1; //d 为冒泡方向的标识,1 为向上,-1 为向下
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