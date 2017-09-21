#include <iostream>
#include <cstdio>

using namespace std;

/*
 * 深拷贝
 */

class Rect{
public:
	Rect(){
		p = new int(100); //p指向堆中分配的一段空间
	}

	Rect(const Rect& r){ //深拷贝
		width = r.width;
		height = r.height;
		p = new int; //重新分配动态空间
		*p = *(r.p);
	}

	~Rect(){
		if(p != NULL)
			delete p;
	}

private:
	int width;
	int height;
	int *p;
};

int main(){
	Rect rect1;

	Rect Rect2(rect1);

	return 0;
}
