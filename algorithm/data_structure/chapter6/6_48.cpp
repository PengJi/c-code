int found=FALSE;
Bitree* Find_Near_Ancient(Bitree T,Bitree p,Bitree q){
	//�������T �н��p ��q �������ͬ����
	Bitree pathp[ 100 ],pathq[ 100 ]
		Findpath(T,p,pathp,0);
	found=FALSE;
	Findpath(T,q,pathq,0);
	for(i=0;pathp[i]==pathq[i]&&pathp[i];i++); 
	return pathp[--i];
}
void Findpath(Bitree T,Bitree p,Bitree path[ ],int i){
	//���T ��p ·���ĵݹ��㷨
	if(T==p){
		found=TRUE;
		return;
	}
	path[i]=T;
	if(T->lchild) Findpath(T->lchild,p,path,i+1); //���������м���Ѱ��
	if(T->rchild&&!found) Findpath(T->rchild,p,path,i+1); //���������м���Ѱ��
	if(!found) 
		path[i]=NULL;
}