void Print_Hash(HashTable H){
	//����һ����ĸ˳�����Hash ���е����йؼ���,���д����ͻ��������̽�⿪�Ŷ�ַ��
	for(i=1;i<=26;i++)
		for(j=i;H.elem[j].key;j=(j+1)%hashsize[sizeindex]) 
			if(H(H.elem[j].key)==i) printf("%s\n",H.elem[j]);
}
int H(char *s){//��Hash ����
	if(s) 
		return s[0]-96; 
	else return 0;
}