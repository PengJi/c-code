void GListPrintElem(GList A,int layer){
	//�ݹ��㷨�������ԭ�Ӽ������ڲ��
	if(!A)
		return;
	if(!A->tag)
		cout<<A->atom<<" "<<a->layer;
	else{
		GListPrintElem(A->ptr.hp,layer+1);
		GListPrintElem(A->prt.tp,larer);
	}
}