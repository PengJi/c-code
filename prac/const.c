#include <iostream>

using namespace std;

int main(){
	int a=4,b=5;
	int &m = a;
	int &n = m;

	n = 10;
	cout<<a<<endl;
	m = 6;
	cout<<a<<endl;
	cout<<n<<endl;

	const int &h = b;
	//h = 10;  //出错，const引用表示，试图通过此引用去(间接)改变其引用的对象的值时，编译器会报错！
	cout<<h<<endl;
}
