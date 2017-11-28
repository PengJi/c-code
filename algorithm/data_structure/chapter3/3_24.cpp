int g(int m,int n){
	if(m==0&&n>=0)
		s=0;
	else if(m>0&&n>=0)
		s=n+g(m-1,2*n);
	else 
		return;
	return s;
}