int Is_Descendant_P(int u,int v){
	//��˫�״洢�ṹ���ж�u �Ƿ�v ������,���򷵻�1,���򷵻�0
	for(p=u;p!=v&&p;p=T[p]);
	if(p==v) 
		return 1;
	else 
		return 0;
}