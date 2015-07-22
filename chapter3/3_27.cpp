//递归算法
int akm(int m,int n){
	if(m==0)
		akm=n+1;
	else if(n==0)
		akm=akm(m-1,1);
	else{
		g=akm(m,n-1);
		akm=akm(m-1,g);
	}
	return akm;
}
//非递归算法
int akm(int m,int n){
	//利用栈实现递归算法
	top=0;
	s[top].mval=m;
	s[top].nval=n;
	do{
		while(s[top].mval){
			while(s[top].nval){
				top++;
				s[top].mval=s[top-1].mval;
				s[top].nval=s[top-1].nval-1;
			}
			s[top].mval--;
			s[top].nval=1;
		}
		if(top>0){
			top--;
			s[top].mval--;
			s[top].nval=s[top+1].nval+1;
		}
	}while(top!=0||s[top].mval1=0);
	akm=s[top].nval+1;
	top--;
	return akm;
}
