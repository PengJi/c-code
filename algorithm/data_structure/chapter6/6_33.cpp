int Is_Descendant_C(int u,int v){
	//�ں��Ӵ洢�ṹ���ж�u �Ƿ�v ������,���򷵻�1,���򷵻�0
	if(u==v) 
		return 1;
	else{
		if(L[v])
			if (Is_Descendant(u,L[v])) 
				return 1;
		if(R[v])
			if (Is_Descendant(u,R[v])) 
				return 1;
	}
	return 0;
}