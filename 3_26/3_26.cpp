float sqrtRecursive(float A,float p,float e){
	//递归方法求平方根
	if(abs(p*p-A)<=e)
		return p;
	else
		return sqrtRecursive(A,(p+A/p),e);
}
float sqrtNonRecursive(float A,float p,float e){
	//非递归方法求平方根
	while(abs(p*p-A)>=e)
		p=(p+A/p)/2;
	return p;
}