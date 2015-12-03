void StrAssign(StringType &T,char chars[]){
	//用字符数组chars给串T赋值
	for(i=0,T[0]=0;chars[i];T[0]++,i++)
		T[i+1]=chars[i];
}