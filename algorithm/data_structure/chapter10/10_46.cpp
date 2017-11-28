typedef struct {
	int key;
	int pos;
} Shadow; //影子序列的记录类型
void Shadow_Sort(Rectype b[ ],Rectype &a[ ],int n){
	//对元素很大的记录序列b进行排序,结果放入a中,不移动元素
	Shadow d[MAXSIZE];
	for(i=0;i<n;i++){
		d[i].key=b[i].key;
		d[i].pos=i;
	}
	for(i=n-1,change=1;i>1&&change;i--){ //对影子序列执行冒泡排序
		change=0;
		for(j=0;j<i;j++)
			if(d[j].key>d[j+1].key){
				d[j]<->d[j+1];
				change=1;
			}
	}
	for(i=0;i<n;i++)
		a[i]=b[d[i].pos];
}