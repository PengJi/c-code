//纯虚函数
#include <iostream>
using namespace std;

class area_c1{
protected:
	double height;
	double width;
public:
	area_c1(double r,double s){
		height=r;
		width=s;
	}
	virtual double area()=0;
};

class rectangle:public area_c1{
public:
	rectangle(double r,double s):area_c1(r,s){}
	double area(){
		return height*width;
	}
};

class isosceles:public area_c1{
public:
	isosceles(double r,double s):area_c1(r,s){}
	double area(){
		return height*width/2;
	}
};

int main(){
	area_c1 *p;
	rectangle b(10.0,5.0);
	isosceles i(4.0,6.0);
	p=&b;
	cout<<"the rectangle area is "<<p->area()<<endl;
	p=&i;
	cout<<"the isoscels area is "<<p->area()<<endl;
	
	return 0;
}
