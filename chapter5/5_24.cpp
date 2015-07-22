typedef struct{
	int seq;
	int e;
}SElem;
typedef struct{
	SElem data[MaxSize];
	int mu,nu,tu;
}SMatrix;
int SMatrixLoc(SMatrix a,int i,int j,int &e){
	s=i*A.nu+j+1;
	p=1;
	while(A.data[p].seq<s)
		p++;
	if(A.data[p].seq==s){
		e=A.data[p].e;
		return 1;
	}
	return 0;
}