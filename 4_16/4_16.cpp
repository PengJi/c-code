int StrCompare(StringType s,StringType t){
	//���ıȽϣ����ʱ������0��s>tʱ������������s<tʱ�����ظ���������ʱ�����ز�ֵ
	for(i=1;i<=s[0]&&i<=t[0]s[i]==t[i];i++);
	if(i>s[0]&&i>t[0])
		return 0;
	else if(i>s[0])
		return -t[i];
	else if(i>t[0])
		return s[i];
	else 
		return s[i]-t[i];
}