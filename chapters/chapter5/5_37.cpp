void GListDelElem(GList &A,int x){
	//�ӹ����A��ɾ������ֵΪx��ԭ��
	if(A&&A->ptr.hp){
		if(A->ptr.hp->tag)
			GListDelElem(A->ptr.hp,x);
		else if(!A->ptr.hp->tag&&A->ptr.hp->atom==x){
			q=A;
			A=A->ptr.tp;
			free(q);
			GListDelElem(A,x);
		}
	}
	if(A&&A->ptr.tp)
		GListDelElem(A->ptr.tp,x);
}