void stringReverse(StringType s,StringType &r){
	//ÇósµÄÄæ´®r
	StrAssign(r,'');
	for(i=strlen(s);i;i--){
		StrAssign(c,SubString(s,i,1));
		StrAssign(r,Concat(r,c));
	}
}