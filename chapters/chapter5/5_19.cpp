void getSaddle(int A[m][]n){
	//������е�����
	for(int i=0;i<m;i++){
		for(min=A[i][0],j=0;j<n;i++){
			if(A[i][j]>min)
				min=A[i][j];
		}
		for(j=0;j<n;j++){
			if(A[i][j]==min){
				for(flag=1,k=0;k<m;k++){
					if(min<A[k][j])
						flag=0;
				}
				if(flag)
					cout<<"����:"<<A[i][j]<<endl;
			}
		}
	}
}
