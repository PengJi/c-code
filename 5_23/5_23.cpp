typedef struct{
	int j;
	int e;
}DSElem;
typedef struct{
	DSElem data[MaxSize];
	int cpot[MaxRow];
	int mu,nu,tu;
}DSMatrix
int DSMatrixLoc(DSMatrix A,int i,int j,int &e){
	//求二元组矩阵的元素A[i][j]的值e
	for(s=A.cpot[i];s<A.cpot[i+1]&&A.data[s].j != j;s++);
	if(s<A.cpot[i+1] && A.data[s].j==j){
		e=A.data[s];
		return 1;
	}
	return 0;
}