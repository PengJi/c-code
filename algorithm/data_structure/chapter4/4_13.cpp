int deleteSubString(StringType &S,StringType t){
	//�Ӵ�s��ɾ��������t��ͬ���Ӵ���������ɾ������
	for(n=0,i=1;i<strlen(s)-strlen(t)+1;i++){
		if(!StrCompare(SubString(s,i,strlen(t)),t)){
			StrAssign(head,SubString(S,1,i-1));
			StrAssign(tail,SubString(S,i+strlen(t),strlen(s)-i-strlen(t)+1));
			StrAssign(S,Concat(head,tail));
			n++;
		}
	}
	return n;
}