typedef struct{
	char ch;
	int num;
}charnum;
void strCharCount(StringType S){
	//统计串S中字符的种类和个数
	charnum T[MaxSize];
	for(i=1;i<=S[0];i++){
		c=S[i];
		j=0;
		while(T[j].ch&&T[j].ch!=c)
			j++;
		if(T[j].ch)
			T[j].num++;
		else{
			T[j].ch=c;
			T[j].num++;
		}
	}
	for(j=0;T[j].ch;j++)
		cout<<T[j].ch<<":"<<T[j].num<<endl;
}