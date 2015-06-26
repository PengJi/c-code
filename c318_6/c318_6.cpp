#define NULL 0
#define NEWSIZE 1000
char newbuf[NEWSIZE];
char *newp=newbuf;

char new(int n){
	if(newp+n <= newbuf+NEWSIZE){
		newp=newp+n;
		return (newp-n);
	}else
		return NULL;
}

free(char *p){
	if((p>= newbuf) && (p<newbuf+NEWSIZE))
		newp=p;
}