int GetDegreeCSTree(CSTree T){
	//�����ֵ������ʾ����T �Ķ�
	if(!T->firstchild) 
		return 0; 
	else
	{
		degree=0;
		for(p=T->firstchild;p;p=p->nextsib)
			degree++;
		for(p=T->firstchild;p;p=p->nextsib){
			d=GetDegreeCSTree(p);
			if(d>degree) degree=d;
		}
		return degree;
	}
}