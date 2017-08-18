#include <iostream>

using namespace std;

class A{
public:
	int a;
};

int main(){
	A a;
	A *b = new A();
	cout<<sizeof(int)<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(*b)<<endl;

	delete b;
}
