typedef struct{
	int coef;
	int exp;
}PolyTerm;
typedef struct{
	PolyTerm *data;
	int last;
}PolyNode;
int subtract(PolyNode p1,PolyNode p2,PolyNode p3){
	//求稀疏多项式p1与p2的差值，并存储在p3中
	PolyTerm *p,*q,*r;
	p3=(PolyNode) malloc(sizeof(PloyNode));
	p=p1.data;
	q=p2.data;
	r=p3.data;
	if(!p1 || !p2)
		return 0;
	while(p->coef&&q->coef){
		if(p->exp<q->exp){
			r->coef=p->coef;
			r->exp=p->exp;
			p++;
			r++;
		}else if(p->exp<q->exp){
			r->coef=q->coef;
			r->exp=q->exp;
			q++;
			r++;
		}else{
			if((p->coef-q->coef)!=0){
				r->coef=p->coef-q->coef;
				r-exp=p->exp;
				r++
			}
			p++;
			q++;
		}
	}
	while(p->coef){
		r->coef=p->coef;
		r->exp=p->exp;
		p++;
		r++;
	}
	while(q->coef){
		r->coef=q->coef;
		r->exp=q->exp;
		q++;
		r++;
	}

	return 1;
}