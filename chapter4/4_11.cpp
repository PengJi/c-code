void stringSub(StringType s,StringType t,StringType &r){
	//求所有包含在串s中而t中没有的字符构成的新串r
	StrAssign(r,'');
	for(i=1;i<=strlen(s);i++){
		StrAssign(c,SubString(s,i,1));
		for(j=1;j<i&&StrCompare(c,SubString(s,j,1));j++);
		if(i==j){
			for(k=1;k<=strlen(t)&&StrCompare(c,SubString(t,k,1));k++);
			if(k>strlen(t))
				StrAssign(r,Concat(r,c));
		}
	}
}