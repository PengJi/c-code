//纯虚函数
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

//球体
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

//圆柱体
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

//立方体
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
	cout<<"球体的半径:"<<ptr->print_ra()<<endl;
	cout<<"球体表面积:"<<ptr->sruface_area()<<endl;
	cout<<"球体体积:"<<ptr->volume()<<endl;
	ptr=&obj2;
	cout<<"圆柱体半径:"<<ptr->print_ra()<<endl;
	cout<<"圆柱体高:"<<ptr->print_he()<<endl;
	cout<<"圆柱体表面积:"<<ptr->sruface_area()<<endl;
	cout<<"圆柱体体积:"<<ptr->volume()<<endl;
	ptr=&obj3;
	cout<<"立方体长:"<<ptr->print_ra()<<endl;
	cout<<"立方体表面积:"<<ptr->sruface_area()<<endl;
	cout<<"立方体体积:"<<ptr->volume()<<endl;

	return 0;
}
