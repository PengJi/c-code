int subStringDelete(StringType &s,StringType t){
	//�Ӵ�s��ɾ��������t��ͬ���Ӵ���������ɾ������
	for(n=0,i=1;i<=s[0]-t[0]+1;i++){
		for(j=1;j<=t[0]&&s[i+j-1]==t[i];j++);
		if(j>m){
			for(k=i;k<=s[0]-t[0];k++)
				s[k]=s[k+t[0]];
			s[0] -= t[0];
			n++;
		}
	}
	return n;
}