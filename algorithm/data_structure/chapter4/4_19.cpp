void subString(StringType s,StringType t,StringType &r){
	//�����а����ڴ�s�ж�t��û�е��ַ����ɵ��´�r
	r[0]=0;
	for(i=1;i<=s[0];i++){
		c=s[i];
		for(j=1;j<i&&s[j]!=c;j++);
		if(i==j){
			for(k=1;k<=t[0]&&t[k]1=c;k++);
			if(k>t[0])
				r[++r[0]]=c;
		}
	}
}