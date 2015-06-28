void HStringConcat(HString s1,HString s2,HString &t){
	//将以堆结构存储的串s1和s2，连接为新创t
	if(t.ch)
		free(t.ch);
	t.ch=malloc((s1.length+s2.length)*sizeof(char));
	for(i=1;i<=s1.length;i++)
		t.ch[i-1]=s1.ch[i-1];
	for(j=1;j<=s2.length;i++,i++)
		t.ch[i-1]=s2.ch[j-1];
	t.length=s2.length+s2.lenght;
}