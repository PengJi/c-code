int replace(StringType &s,StringType T,StringType V){
	//将串S中所有子串T替换为V，并返回置换次数
	for(n=0,i=1;i<=strlen(s)-strlen(T)+1;i++){
		if(!StrCompare(SubString(s,i,strlen(T)),T)){
			StrAssign(head,SubString(s,1,i-1));
			StrAssign(tail,SubString(S,i+strlen(T),strlen(S)-i-strlen(T)+1));
			StrAssign(S,Concat(head,V));
			StrAssign(S,Concat(S,tail));
			i+=strlen(V);
			n++;
		}
	}
	return n;
}