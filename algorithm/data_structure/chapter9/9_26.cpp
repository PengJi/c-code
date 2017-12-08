int Search_Bin_Recursive(SSTable ST,int key,int low,int high){
	//ÕÛ°ë²éÕÒµÄµÝ¹éËã·¨
	if(low>high) 
		return 0;
	mid=(low+high)/2;
	if(ST.elem[mid].key==key) 
		return mid;
	else if(ST.elem[mid].key>key)
		return Search_Bin_Recursive(ST,key,low,mid-1);
	else 
		return Search_Bin_Recursive(ST,key,mid+1,high);
}