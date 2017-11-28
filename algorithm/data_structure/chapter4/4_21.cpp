typedef struct{
	char ch;
	LStrNode *next;
}LStrNode,*LString
void StrAssign(LString &s,LString t){
	//把串t赋值给s
	LStrNode *p,*q;
	s=(LStrNode *) malloc(sizeof(LStrNode));
	for(q=s,p=t->next;p;p=p->next){
		r=(LStrNode *) malloc(sizeof(LStrNode));
		r->ch=p->ch;
		q->next=r;
		q=r;
	}
	q->next=NULL;
}
void StrCopy(LString &s,LString t){
	//把t复制为s
	for(p=s->next,q=t->next;p&&q;p=p->next,q=q->next){
		p->ch=q->ch;
		pre=p;
	}
	while(q){
		p=(LStrNode *) malloc(sizeof(LStrNode));
		p->ch=q->ch;
		pre->next=p;
		pre=p;
	}
	p->next=NULL;
}
int StrCompare(LString s,LString t){
	//串的比较
	for(p=s->next,q=t->next;p&&q&&p->ch==q->ch;p=p->next,q=q->next);
	if(!p&&!q)
		return 0;
	else if(!p)
		return -(q->ch);
	else if(!q)
		return p->ch;
	else
		return p->ch-q->ch;
}
int StrLength(LString s){
	//求串s的长度
	int i;
	for(i=0,p=s->next;p;p=p->next,i++);
	return i;
}
LString Concat(LString s,LString t){
	//连接串s和串t形成新串
	LString p;
	p=malloc(sizeof(LStrNode));
	for(q=p,r=s->next;r;r=r->next){
		q->next=(LStrNode *)malloc(sizeof(LStrNode));
		q=q->next;
		q->ch=r->ch;
	}
	for(r=t->next;r;r=r->next){
		q->next=(LStrNode *) malloc(sizeof(LStrNode));
		q=q->next;
		q->ch=r->ch;
	}
	q->next=NULL;
	return p;
}
LString SubString(LString s,int start,int len){
	//截取串s从start开始的len长度
	LString p;
	p=malloc(sizeof(LStrNode));
	q=p;
	for(r=s;start;start--,r=r->next);
	for(int i=1;i<=len;i++,r=r->next){
		q->next=(LStrNode *) malloc(sizeof(LStrNode));
		q=q->next;
		q->ch=r->ch;
	}
	q->next=NULL;
	return p;
}
