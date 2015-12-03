int exps[MaxSize];
int maxm,n;
void printPolyDescend(int *a,int m){
	//按降幂顺序输出m元多项式的项，各项的系数已存储于m维数组中，数组的头指针为a
	maxm=m;
	for(i=m*n;i>=0;i--)
		getAll(a,m,i,0);
}
void getAll(int *a,int m,int i,int seq){
	//递归求出所有和为i的m个自然数
	if(seq==maxm)
		printNomial(a,exps);
	else{
		min=i-(m-1)*n;
		if(min<0)
			min=0;
		max=n<i?n:i;
		for(j=min;j<=max;j++){
			exps[seq]=j;
			getAll(a,m-1,i-j,seq+1);
		}
	}
}
void printNomial(int *a,int exps[]){
	//输出一个项
	pos=0;
	for(i=0;i<maxm;i++){
		pos*=n;
		pos+=exps[i];
	}
	coef = *(a+pes);
	if(!coef)
		return;
	else if(coef>0)
		printf("+");
	else if(coef<0)
		printf("-");
	if(abs(coef)!=1)
		cout<<abs(coef);
	for(i=0;i<maxm;i++)
		if(exps[i]){
			cout<<"x";
			cout<<i;
			cout<<"E";
			if(exps[i]>1)
				cout<<exp[i];
		}
}