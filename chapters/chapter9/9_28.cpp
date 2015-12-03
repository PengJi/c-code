typedef struct {
	int maxkey;
	int firstloc;
} Index;
typedef struct {
	int *elem;
	int length;
	Index idx[MAXBLOCK];
	int blknum;
} IdxSqList;
int Search_IdxSeq(IdxSqList L,int key){
	//分块查找,用折半查找法确定记录所在块,块内采用顺序查找法
	if(key>L.idx[L.blknum].maxkey) 
		return ERROR; //超过最大元素
	low=1;high=L.blknum;
	found=0;
	while(low<=high&&!found){
		mid=(low+high)/2;
		if(key<=L.idx[mid].maxkey&&key>L.idx[mid-1].maxkey)
			found=1;
		else if(key>L.idx[mid].maxkey)
			low=mid+1;
		else 
			high=mid-1;
	}
	i=L.idx[mid].firstloc; //块的下界
	j=i+blksize-1; //块的上界
	temp=L.elem[i-1]; //保存相邻元素
	L.elem[i-1]=key; //设置监视哨
	for(k=j;L.elem[k]!=key;k--); //顺序查找
	L.elem[i-1]=temp; //恢复元素
	if(k<i) return ERROR; //未找到
	return k;
}