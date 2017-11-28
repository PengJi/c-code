int IndexNew(StringType e,StringType t){
	//新定位算法
	int i=1;
	int j=1;
	while(i<s[0]&&j<=t[0]){
		if((j!=1&&s[i]==t[j])||(j==1&&s[i]==t[j])&&s[i+t[0]-1]==t[t[0]]){
			i=i+j-1;
			j=1;
		}else{
			i++;
			j++;
		}
	}
	if(j>t[0])
		return i-t[0];

}