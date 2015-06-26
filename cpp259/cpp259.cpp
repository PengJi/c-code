//5.20
#include <iostream>
using namespace std;

class Container{
protected:
	double radius;
	double height;
public:
	Container(double ra){
		Container::radius=ra;
	}
	double print_ra(){
		return radius;
	}
	double print_he(){
		return height;
	}
	virtual double sruface_area()=0;
	virtual double volume()=0;
};

class Sphere:public Container{
public:
	Sphere(double ra):Container(ra){}
	double surface_area(){
		return 4*3.1416*radius*radius;
	}
	double volume(){
		return 3.1416*radius*radius*radius*4/3;
	}
};

class Cylinder:public Container{
public:
	Cylinder(double ra,double he):Container(ra){
		height=he;
	}
	double surface_area(){
		return 2*3.1416*radius*(height+radius);
	}
	double volume(){
		return 3.1416*radius*radius*height;
	}
};

class Cube:public Container{
public:
	Cube(double ra):Container(ra){}
	double surface_area(){
		return radius*radius*6;
	}
	double volume(){
		return radius*radius*radius;
	}
};

int main(){
	Container *ptr;
	Sphere obj1(8.0);
	Cylinder obj2(3,5);
	Cube obj3(5.0);
	ptr=&obj1;
	cout<<"����뾶:"<<ptr->print_ra()<<endl;
	cout<<"��������:"<<ptr->sruface_area()<<endl;
	cout<<"�������:"<<ptr->volume()<<endl;
	ptr=&obj2;
	cout<<"Բ����뾶:"<<ptr->print_ra()<<endl;
	cout<<"Բ�����:"<<ptr->print_he()<<endl;
	cout<<"Բ��������:"<<ptr->sruface_area()<<endl;
	cout<<"Բ�������:"<<ptr->volume()<<endl;
	ptr=&obj3;
	cout<<"������䳤:"<<ptr->print_ra()<<endl;
	cout<<"����������:"<<ptr->sruface_area()<<endl;
	cout<<"���������:"<<ptr->volume()<<endl;

	return 0;
}