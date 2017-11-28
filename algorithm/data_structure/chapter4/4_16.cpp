int StrCompare(StringType s,StringType t){
	//串的比较，相等时，返回0，s>t时，返回正数，s<t时，返回复数，不等时，返回差值
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