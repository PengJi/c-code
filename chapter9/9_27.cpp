int Locate_Bin(SSTable ST,int key){
	//折半查找,返回小于或等于待查元素的最后一个结点号
	int *r;
	r=ST.elem;
	if(key<r .key)
		return 0;
	else if(key>=r[ST.length].key)
		return ST.length;
	low=1;high=ST.length;
	while(low<=high){
		mid=(low+high)/2;
		if(key>=r[mid].key&&key<r[mid+1].key)
			return mid;
		else if(key<r[mid].key)
			high=mid;
		else 
			low=mid;
	} 
}
