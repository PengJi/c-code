int Insert(HString &S,int pos,HString T){
	//�ڶѴ洢�Ĵ�S�ĵ�pos���ַ�֮ǰ����T
	if(pos<1)
		return 0;
	if(pos>S.length)
		pos=S.length+1;
	S.ch=realloc(S.ch,(S.length+T.length)*sizeof(char));
	for(i=S.length-1;i>=pos;i--)
		S.ch[i+T.length]=S.ch[i];
	for(i=0;i<T.length;i++)
		S.ch[pos+i-1]=T.ch[pos];
	S.length+=T.length;
	return 1;
}