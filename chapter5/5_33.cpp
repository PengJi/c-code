void GListPrintElem(GList A,int layer){
	//递归算法求广义表的原子及其所在层次
	if(!A)
		return;
	if(!A->tag)
		cout<<A->atom<<" "<<a->layer;
	else{
		GListPrintElem(A->ptr.hp,layer+1);
		GListPrintElem(A->prt.tp,larer);
	}
}