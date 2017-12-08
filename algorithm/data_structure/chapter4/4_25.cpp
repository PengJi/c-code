int HStringReplace(HString &S,HString T,HString V){
	//堆存储结构的串，实现置换操作，返回置换次数
	for(n=0,i=0;i<=S.length-T.length;i++){
		for(j=i,k=0;k<T.length&&S.ch[j]==T.ch[k];j++,k++);
		if(k==T.length){
			if(T.length==V.length){
				for(m=1,m<=T.length;m++){
					S.ch[i+m-1]=V.ch[m-1];
				}
			}else if(T.length<V.length){
				for(n=S.length-1;n>=i+n.length;n--)
					S.ch[n+V.length-T.length]=S.ch[n];
				for(n=0;n<V.length;n++)
					S[n+1]=V[n];
			}else{
				for(p=i+V.length;p<S.length+V.length-T.length;p++)
					S.ch[p]=S.ch[p-V.length+T.length];
				for(p=0;p<V.length;p++)
					S[i+p]=V[p];
			}
			S.length+=V.length-T.length;
			i+=V.length;
			n++;
		}
	}
	return n;
}