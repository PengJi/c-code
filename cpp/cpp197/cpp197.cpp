//函数继承
#include <iostream>
using namespace std;

class gcd_class{
private:
	int n;
	int d;
public:
	gcd_class(int p,int q);
	long func(int j,int k);

};

gcd_class::gcd_class(int p,int q){
	n=p;
	d=q;
}
long gcd_class::func(int j,int k){
	if(k==0)
		return j;
	else 
		return func(k,j%k);
}

class derived:public gcd_class{
protected:
	char *c;
public:
	derived(char *m);
	long pfunc(int l,int r);
};
derived::derived(char *m):gcd_class(1,1){
	c=m;
}
long derived::pfunc(int l,int r){
	return gcd_class::func(l,r);
}

int main(){
	derived ob("output n!\n");
	int n,d;
	cout<<"please input two int:";
	cin>>n>>d;
	cout<<"gcd("<<n<<","<<d<<")"<<ob.pfunc(n,d)<<endl;
	return 0;
}
