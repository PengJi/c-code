typedef struct {
	int key;
	int pos;
} Shadow; //Ӱ�����еļ�¼����
void Shadow_Sort(Rectype b[ ],Rectype &a[ ],int n){
	//��Ԫ�غܴ�ļ�¼����b��������,�������a��,���ƶ�Ԫ��
	Shadow d[MAXSIZE];
	for(i=0;i<n;i++){
		d[i].key=b[i].key;
		d[i].pos=i;
	}
	for(i=n-1,change=1;i>1&&change;i--){ //��Ӱ������ִ��ð������
		change=0;
		for(j=0;j<i;j++)
			if(d[j].key>d[j+1].key){
				d[j]<->d[j+1];
				change=1;
			}
	}
	for(i=0;i<n;i++)
		a[i]=b[d[i].pos];
}