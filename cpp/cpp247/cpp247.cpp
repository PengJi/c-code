//����C++��̬�ԣ����������Ρ����κ�Բ�����
#include <iostream>
using namespace std;

class Figure{
public:
	Figure(double a,double b){
		x=a;y=b;
	}
	virtual void area(){
		cout<<"�ڻ����ж����麯����Ϊ�������ṩһ�������ӿڣ��Ա������������Ҫ���¶����麯����"<<endl;
	}
protected:
	double x,y;
};

class Triangle:public Figure{
public:
	Triangle(double a,double b):Figure(a,b){}
	void area(){
		cout<<"�����εĸ��� "<<x<<"������ "<<y;
		cout<<"������� "<<0.5*x*y<<endl;
	}
};

class Square:public Figure{
public:
	Square(double a,double b):Figure(a,b){}
	void area(){
		cout<<"���εĳ��� "<<x<<"������ "<<y;
		cout<<"������� "<<x*y<<endl;
	}
};

class Circle:public Figure{
public:
	Circle(double a):Figure(a,a){}
	void area(){
		cout<<"Բ�İ뾶�� "<<x;
		cout<<"������� "<<3.1416*x*x<<endl;
	}
};

int main(){
	Figure *p;
	Triangle t(10.0,6.0);
	Square s(10.0,6.0);
	Circle c(10.0);
	p=&t;
	t.area();
	p->area();

	p=&s;
	s.area();
	p->area();

	p=&c;
	c.area();
	p->area();

	return 0;
}