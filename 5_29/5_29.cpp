void MPListAdd(MPList A,MPList B,MPList &C){
	//递归算法，广义表存储结构的多项式相加
	C=(MPLNode *)malloc(sizeof(MPLNode));
	if(!A->tag&&!B->tag){
		C->coef=A->coef+B->coef;
		if(!C->coef){
			free(C);
			C=NULL;
		}
	}else if(A->tag&&B->tag){//两个多项式相加
		p=A;
		q=B;
		pre=NULL;
		while(p&&q){
			if(p->exp==q->exp){
				C=(MPLNode *)malloc(sizeof(MPLNode));
				C->exp=p->exp;
				MPListAdd(A->hp,B->hp,c->hp);
				pre->tp=C;
				pre=C;
				p=p->tp;
				q=q->tp;
			}else if(p->exp>q->exp){
				C=(MPLNode *)malloc(sizeof(MPLNode));
				C->exp=p->exp;
				C->hp=A->hp;
				pre->tp=C;
				pre=C;
				p=p->tp;
			}else{
				C=(MPLNode *)malloc(sizeof(MPLNode));
				C->exp=q->exp;
				C->hp=B->hp;
				pre->tp=C;
				pre=C;
				q=q->tp;
			}
		}
		while(p){
			C=(MPLNode *)malloc(sizeof(MPLNode));
			C->exp=p->exp;
			C->hp=p->hp;
			pre->tp=C;
			pre=C;
			p=p->tp;
		}
		while(q){
			C=(MPLNode *)malloc(sizeof(MPLNode));
			C->exp=q->exp;
			C->hp=q->hp;
			pre->tp=C;
			pre=C;
			q=q->tp;
		}
	}else if(A->tag && !B->tag){//多项式和常数项相加
		x=B->coef;
		for(p=A;p->tp->tp;p=p->tp);
		if(p->tp->exp==0)
			p->tp->coef += x;
		if(!p->tp->coef){
			free(p->tp);
			p->tp=NULL;
		}else{
			q=(MPLNode *)malloc(sizeof(MPLNode));
			q->coef=x;
			q->exp=0;
			q->tag=0;
			q->tp=NULL;
			q->tp=q;
		}
	}else{
		x=A->coef;
		for(p=B;p->tp-tp;p=p->tp);
		if(p->tp->exp==0)
			p->tp->coef+=x;
		if(!p->tp->coef){
			free(p->tp);
			p->tp=NULL;
		}else{
			q=(MPLNode *)malloc(sizeof(MPLNode));
			q->coef=x;
			q->exp=0;
			q->tag=0;
			q->tp=NULL;
			p->tp=q;
		}
	}
}