int maxh;
int Printpath_MaxdepthS1(Bitree T){
	//求深度等于树高度减一的最靠左的结点
	Bitree pathd;
	maxh=Get_Depth(T);
	if(maxh<2) 
		return 0;
	Find_h(T,1);
	return 1;
}
void Find_h(Bitree T,int h){
	path[h]=T;
	if(h==maxh-1){
		for(i=1;path[i];i++) 
			printf("%c",path[i]->data);
		exit; 
	}
	else{
		if(T->lchild) 
			Find_h(T->lchild,h+1);
		if(T->rchild) 
			Find_h(T->rchild,h+1);
	}
	path[h]=NULL; 
}