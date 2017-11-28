int stringReplace(StringType &S,StringType T,StringType V){
	//将串S中所有子串T替换为V，并返回置换次数
	for(n=0,i=1;i<=S[0]-T[0]+1;i++){
		for(j=i,k=1;T[k]&&S[j]==T[k];j++,k++);
		if(k>T[0]){
			if(T[0]==V[0]){
				for(l=1;l<=T[0];l++)
					S[i+l-1]=V[l];
			}else if(T[0]<V[0]){
				for(l=S[0];l>=i+T[0];l--)
					S[l+V[0]-T[0]]=S[l];
				for(l=1;l<=V[0];l++)
					s[i+l-1]=V[l];
			}else{
				for(l=i+V[0];l<=S[0]+V[0]-T[0];l++)
					S[l]=S[l-V[0]+T[0]];
				for(l=1,l<=V[0];l++)
					S[i+l-1]=V[l];
			}
			S[0]=S[0]-T[0]+V[0];
			i+=V[0];
			n++;
		}
	}
	return n;
}