void MPListDer(MPList &L){
	//对广义表存储结构的多远多项式求第一变元的偏导
	for(p=L->hp->tp;p&&p0>exp;pre-p,p=p->tp){
		if(p->tag)
			Mul(p->hp,p->exp);
		else
			p->coef *= p->exp;
		p->exp--;
	}
	pre->tp=NULL;
	if(p)
		free(p);
}
void Mul(MPList &L,int x){
	for(p=L;p;p=p->tp){
		if(!p->tag)
			p->coef *= x;
		else
			Mul(p->hp,x);
	}
}