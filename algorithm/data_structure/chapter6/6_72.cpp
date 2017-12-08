void PrintCTree(int e,int i=0){
	//按凹入表形式打印输出树的元素，i为结点所在层次
	for(j=1;j<=i;j++)
		cout<<" ";
	cout<<T.nodes[e].data<<endl;
	for(p=T.nodes[e].firstchild;p;p=p->next)
		PrintCTree(p->child,i+1);
}