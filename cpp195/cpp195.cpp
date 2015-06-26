#include <iostream>
#include <iomanip>
using namespace std;

class table{
public:
	table(int p){
		i=p;
	}
	void ascii(void);
protected:
	int i;
};
void table::ascii(void){
	int k=1;
	for(;i<127;i++){
		cout<<setw(4)<<i<<" "<<(char)i;
		if((k)%12==0)
			cout<<"\n";
		k++;
	}
}

class der_table:public table{
public:
	der_table(int p,char *m):table(p){
		c=m;
	}
	void print(void);
protected:
	char *c;
};
void der_table::print(void){
	cout<<c<<"\n";
	table::ascii();
}

int main(){
	der_table ob(32,"ASCII value---char");
	ob.print();
	cout<<"\n";
	
	return 0;
}



