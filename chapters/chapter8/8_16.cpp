void Mem_Contract(Heap &H){
	//�Զ�ִ�д洢�����㷨
	q=MemStart;
	j=0;
	for(i=0;i<Max_ListLen;i++){
		if(H.list[i].stadr->tag){
			s=H.list[i].length;
			p=H.list[i].stadr;
			for(k=0;k<s;k++){
				*(q++)=*(p++);
			}
			H.list[j].stadr=q;
			H.list[j].length=s;
			j++;
		}
	}
}