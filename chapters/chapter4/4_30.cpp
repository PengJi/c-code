void getRepSub(StringType S)[
	//��s����ظ��Ӵ���λ�úͳ���
	//ʹ�����α���������������б�Ϊs1��s2����Ϊs�ĸ������ڱ���s1ʱ�����α���s2�е�ÿ��Ԫ���Ƿ��s1��ͬ��
	//�����ͬ�������s2����һ��Ԫ�أ�������maxlen��pos������ж�maxlen�Ƿ�Ϊ����������¼���maxlen��
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
		cout<<"��ظ��Ӵ�����Ϊ:"<<maxlen<<endl;
		cout<<"λ��1:"<<pos1<<" "<<"λ��2:"<<pos2<<endl;
	}else{
		cout<<"û���ҵ��ظ��Ӵ�";
	}
}