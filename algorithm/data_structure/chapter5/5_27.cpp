void OLMatrixAdd(OLMatrix &A,OLMatrix B){
	//把以十字链表表示的矩阵B加到A上
	for(j=1;j<=A.nu;j++)
		cp[j]=A.chead[j];
	for(i=1;i<A.mu;i++){
		pa=A.rhead[i];
		pb=B.rhead[i];
		pre=NULL;
		while(pb){
			if(pa==NULL || pa->j>pb->j){
				p=(OLNode *) malloc (sizeof(OLNode));
				if(!pre)
					A.rhead[i]=p;
				else
					pre->right=p;
				p->right=pa;
				pre=p;
				p->i=i;
				p->j=pb->j;
				p->e=pb->e;
				if(!A.head[p->j]){
					A.chead[p->j]=p;
					p->down=NULL;
				}else{
					while(cp[p->j]->down)
						cp[p->j]=cp[p->j]->down;
					p->down=cp[p->j]->down;
					cp[p->j]->down=p;
				}
				cp[p->j]=p;
			}else if(pa->j<pb->j){
				pre=pa;
				pa=pa->right;
			}else if(pa->e+pb->e){
				pa->e+=pb->e;
				pre=pa;
				pa=pa->right;
				pb=pb->right;
			}else{
				if(!pre)
					A.rhead[i]=pa->right;
				else
					pre->right=pa->right;
				p=pa;
				pa=pa->right;
				if(A.chead[p->j]==p)
					A.chead[p->j]=cp[p->j]=p->down;
				else 
					cp[p->j]->down=p->down;
				free(p);
			}
		}
	}
}