void StrAssign(StringType &T,char chars[]){
	//���ַ�����chars����T��ֵ
	for(i=0,T[0]=0;chars[i];T[0]++,i++)
		T[i+1]=chars[i];
}