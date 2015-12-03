int found=FALSE;
Bitree* Find_Near_Ancient(Bitree T,Bitree p,Bitree q){
	//求二叉树T 中结点p 和q 的最近共同祖先
	Bitree pathp[ 100 ],pathq[ 100 ]
		Findpath(T,p,pathp,0);
	found=FALSE;
	Findpath(T,q,pathq,0);
	for(i=0;pathp[i]==pathq[i]&&pathp[i];i++); 
	return pathp[--i];
}
void Findpath(Bitree T,Bitree p,Bitree path[ ],int i){
	//求从T 到p 路径的递归算法
	if(T==p){
		found=TRUE;
		return;
	}
	path[i]=T;
	if(T->lchild) Findpath(T->lchild,p,path,i+1); //在左子树中继续寻找
	if(T->rchild&&!found) Findpath(T->rchild,p,path,i+1); //在右子树中继续寻找
	if(!found) 
		path[i]=NULL;
}