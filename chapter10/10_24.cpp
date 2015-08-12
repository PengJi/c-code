void BiInsert_Sort(SqList &L){
	//二路插入排序算法
	int d[MAXSIZE];
	x=L.r.key;
	d=x;
	first=1;
	final=1;
	for(i=2;i<L.length;i++){
		if(L.r[i].key>=x){
			for(j=final;d[j]>L.r[i].key;j--)
				d[j+1]=d[j];
			d[j+1]=L.r[i].key;
			final++;
		}else{
			for(j=first;d[j]<L.r[i].key;j++)
				d[j-1]=d[j];
			d[(j-2)%MAXSIZE+1]=L.r[i].key;
			first=(first-2)%MAXSIZE+1;
		}
	}
	for(i=first,j=1;d[i];i=i%MAXSIZE+1,j++)
		L.r[j].key=d[i];
}