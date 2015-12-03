typedef struct{
	int coef;
	int exp;
}PolyTerm;
typedef struct{
	PolyTerm *data;
	int last;
}PolyNode;
float getValue(PolyNode p,int x0){
	//求稀疏多项式的值
	PolyTerm *q;
	int xp=1;
	q=p.data;
	float sum=0;
	int ex=0;
	while(q->coef){
		while(ex<q->exp)
			xp*=x0;
		sum+=q->coef*xp;
		q++
	}
	return sum;
	
}