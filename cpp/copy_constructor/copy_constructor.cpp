#include <iostream>
#include <cstdio>

using namespace std;

/*
 * 默认拷贝构造函数
 * http://blog.csdn.net/lwbeyond/article/details/6202256
 */

class Rect{
public:
	Rect(){
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
	cout<<"The count of Rect: "<<Rect::getCount()<<endl; //1，拷贝构造函数没有处理静态数据成员

	return 0;
}
