#include <iostream>
using namespace std;
typedef enum{A,B,C,D,E} SchoolName;
typedef enum{Female,Male} SexType;
typedef struct{
	char event[3];  
	SexType sex;
	SchoolName school;
	int score;
} Component;
typedef struct{
	int MaleSum;	
	int FemaleSum;
	int TotalSum;
} Sum;
Sum SumScore(SchoolName sn,Component a[],int n)
{
	Sum temp;
	temp.MaleSum=0;
	temp.FemaleSum=0;
	temp.TotalSum=0;
	int i;
	for(i=0;i<n;i++){
		if(a[i].school==sn){
			if(a[i].sex==Male) temp.MaleSum+=a[i].score;
			if(a[i].sex==Female) temp.FemaleSum+=a[i].score;
		}
	}
	temp.TotalSum=temp.MaleSum+temp.FemaleSum;
	return temp;
}
int main(){
	Component com[5];

	strcpy(com[1].event,"pro");
	com[1].school=A;
	com[1].score=90;
	com[1].sex=Female;

	strcpy(com[2].event,"pro");
	com[2].school=A;
	com[2].score=91;
	com[2].sex=Male;

	strcpy(com[3].event,"pro");
	com[3].school=A;
	com[3].score=92;
	com[3].sex=Male;

	strcpy(com[4].event,"pro");
	com[4].school=A;
	com[4].score=93;
	com[4].sex=Female;

	strcpy(com[5].event,"pro");
	com[5].school=A;
	com[5].score=94;
	com[5].sex=Male;

	Sum num=SumScore(A,com,5);

	cout<<num.FemaleSum<<" "<<num.MaleSum<<" "<<num.TotalSum<<endl;

	return 0;
}