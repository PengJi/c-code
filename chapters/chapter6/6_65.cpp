char Pred,Ind; //ǰ�����к����������Ѿ��ֱ𴢴�������Pre ��In ��
Bitree Build_Sub(int Pre_Start,int Pre_End,int In_Start,int In_End){
	//��������ǰ����������н������������
	sroot=(BTNode*)malloc(sizeof(BTNode)); 
	sroot->data=Pre[Pre_Start];
	for(i=In_Start;In[i]!=sroot->data;i++);
	leftlen=i-In_Start;
	rightlen=In_End-i;
	if(leftlen){
		lroot=Build_Sub(Pre_Start+1,Pre_Start+leftlen,In_Start,In_Start+leftlen-1);
		sroot->lchild=lroot;
	}
	if(rightlen){
		rroot=Build_Sub(Pre_End-rightlen+1,Pre_End,In_End-rightlen+1,In_End);
		sroot->rchild=rroot;
	}
	return sroot;
}