void PrintCSTree(CSTree T,int i){
	//按凹入表形式打印输出树的元素，i表示结点所在层次
	for(j=1;j<=i;j++)
		cout<<" ";
	cout<<T->data<<endl;
	for(p=T->firstchild;p;p=p->nextsib)
		PrintCSTree(p,i+1);
}