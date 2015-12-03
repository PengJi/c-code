typedef enum{0,1} bool;
typedef struct{
	int mu,nu;
	int elem[MaxSize];
	bool map[mu][nu];
}BMMatrix;
void BMMatrixAdd(BMMatrix A,BMMatrix B,BMMatrix &C){
	C.mu=A.mu;
	C.nu=A.nu;
	pa=1;
	pb=1;
	pc=1;
	for(i=0;i<A.mu;i++)
		for(j=0;j<A.nu;j++){
			if(A.map[i][j] && B.map[i][j] &&(A.elem[pa]+B.elem[pb])){
				C.elem[pc]=A.elem[pa]+B.elem[pb];
				C.map[i][j]=1;
				pa++;
				pb++;
				pc++;
			}else if(A.map[i][j] && !B.map[i][j]){
				C.elem[pc]=A.elem[pa];
				C.map[i][j]=1;
				pa++;
				pc++;
			}else if(!A.map[i][j]&&B.map[i][j]){
				C.elem[pc]=B.elem[pb];
				C.map[i][j]=1;
				pb++;
				pc++;
			}
		}
}