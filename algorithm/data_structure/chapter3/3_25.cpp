int FRecursive(int n,int &s){
	//µİ¹éËã·¨
	if(n<0)
		return 0;
	if(n==0)
		s=n+1;
	else{
		FRecusive(n/2,r);
		s=n*r;
	}
	return s;
}
int FNonrecursive(int n,int s){
	//·Çµİ¹éËã·¨
	if(n<0)
		return 0;
	if(n==0)
		s=n+1;
	else{
		InitStack(s);
		while(n!=0){
			a=n;
			b=n/2;
			push(s,{a,b});
			n=b;
		}
		s=1;
		while(!StackEmpty(s)){
			pop(s,t);
			s*=t.a;
		}
		return 1;
	}
}