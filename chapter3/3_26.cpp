float sqrtRecursive(float A,float p,float e){
	//�ݹ鷽����ƽ����
	if(abs(p*p-A)<=e)
		return p;
	else
		return sqrtRecursive(A,(p+A/p),e);
}
float sqrtNonRecursive(float A,float p,float e){
	//�ǵݹ鷽����ƽ����
	while(abs(p*p-A)>=e)
		p=(p+A/p)/2;
	return p;
}