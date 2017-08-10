//链表合并，学号升序
#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)

struct student{
	long num;
	int score;
	student *next;
};

struct student lista,listb;
int n,sum=0;

void main(){
	struct student *create(void);
	struct student *insert(struct student *,struct student *);
	void print(student *);

	student *ahead,*bhead,*abh;
	printf("input list a:\n");
	ahead=create();
	sum=sum+n;
	printf("input list b:\n");
	bhead=create();
	sum=sum+n;
	abh=insert(ahead,bhead);
	print(abh);
}

student *create(void){
	student *p1,*p2,*head;
	n=0;
	p1=p2=(struct student *) malloc (LEN);
	printf("input number & scores of student:\n");
	printf("if number is 0,stop inputing.\n");
	scanf("%d,%d",&p1->num,&p1->score);
	head=NULL;
	//循环建立结点
	while(p1->num != 0){
		n=n+1;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1; 
		p1=(student *) malloc(LEN);
		scanf("%ld,%d",&p1->num,&p1->score);
	}
	p2->next = NULL;
	return head;
}

student *insert(struct student *ah,student *bh){
	student *pa1,*pa2,*pb1,*pb2;
	pa2=pa1=ah;
	pb2=pb1=bh;
	do{
		while((pb1->num>pa1->num) && (pa1->next != NULL)){
			pa2=pa1;
			pa1=pa1->next;
		}
		if(pb1->num <= pa1->num){
			if(ah == pa1)
				ah=pb1;
			else 
				pa2->next = pb1;
			pb1=pb1->next;
			pb2->next=pa1;
			pa2=pb2;
			pb2=pb1;
		}
	}while((pa1->next != NULL) || (pa1==NULL && pb1!=NULL));
	if((pb1 != NULL) && (pb1->num>pa1->num) && (pa1->next == NULL))
		pa1->next = pb1;
	return ah;
}

void print(struct student *head){
	student *p;
	printf("\n There are %d records: \n",sum);
	p=head;
	if(p != NULL)
		do{
			printf("%ld %d\n",p->num,p->score);
			p=p->next;
		}while(p != NULL);
}