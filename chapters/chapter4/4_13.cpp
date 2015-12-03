int deleteSubString(StringType &S,StringType t){
	//从串s中删除所有与t相同的子串，并返回删除次数
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