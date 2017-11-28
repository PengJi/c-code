void getRepSub(StringType S)[
	//求串s的最长重复子串的位置和长度
	//使用两次遍历，假设遍历的列表为s1、s2，均为s的副本，在遍历s1时，依次遍历s2中的每个元素是否和s1相同。
	//如果相同，则遍历s2的下一个元素，并更新maxlen和pos，最后判断maxlen是否为最长，否则重新计算maxlen。
	for(maxlen=0,i=1;i<S[0];i++){
		for(k=0,j=1;j<=S[0]-i;j++){
			if(S[j]==S[j+i])
				k++;
			else
				k=0;
			if(k>maxlen){
				pos1=j-k+1;
				pos2=pos1+i;
				maxlen=k;
			}
		}
	}
	if(maxlen){
		cout<<"最长重复子串长度为:"<<maxlen<<endl;
		cout<<"位置1:"<<pos1<<" "<<"位置2:"<<pos2<<endl;
	}else{
		cout<<"没有找到重复子串";
	}
}