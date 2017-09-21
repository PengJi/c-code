#include <iostream>
#include <cstdio>

using namespace std;

/*
 * 浅拷贝
 */

class Rect{
public:
	Rect(){
		count++;
	}

	Rect(const Rect& r){ //拷贝构造函数
		width = r.width;
		height = r.height;
		count++;
	}

	~Rect(){
		count--;
	}

	static int getCount(){
		return count;
	}

private:
	int width;
	int height;
	static int count;
};

int Rect::count = 0;

int main(){
	Rect rect1;
	cout<<"The count of Rect: "<<Rect::getCount()<<endl; //1

	Rect Rect2(rect1);
	cout<<"The count of Rect: "<<Rect::getCount()<<endl; //2，调用拷贝构造函数

	return 0;
}
