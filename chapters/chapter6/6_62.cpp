int GetDepthCSTree(CSTree T){
	//�����ֵ������ʾ����T �����
	if(!T) 
		return 0;
	else{
		for(maxd=0,p=T->firstchild;p;p=p->nextsib)
			if((d=GetDepthCSTree(p))>maxd) 
				maxd=d;
			return maxd+1;
	}
}