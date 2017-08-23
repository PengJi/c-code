#include <iostream>

using namespace std;

class A{
public:
	int a;
};

// 设计一个类，该类不能被集成，且只能实例化3词
class FinalClass{
public:
	static int count;

	static FinalClass *getInstance(){
		if(count <=0) return NULL;
		count--;
		return new FinalClass;
	}

	static void setCount(int n){
		count = n;
	}

	static void delInstance(FinalClass *instance){
		delete instance;
		pinStance = 0;
	}
private:
	FinalClass(){}
	~FinalClass(){}
}

int FinalClass::count = 0;

int main(){
	A a;
	A *b = new A();
	cout<<sizeof(int)<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(*b)<<endl;

	delete b;

	// 一个类的实例只能有3个
	FinalClass::setCount(3);
	FinalClass *f1 = FinalClass::getInstance();
	FinalClass *f2 = FinalClass::getInstance();
	FinalClass *f3 = FinalClass::getInstance();

	if (f3 == NULL)
	{
		printf("f3 is NULL\n");
	}else{
		printf("f3 not NULL\n");
	}
	FinalClass *f4 = FinalClass::getInstance();
	if(f4 == NULL)
		printf("f4 is NULL\n");
	FinalClass *f5 = FinalClass::getInstance();
	if(f5 == NULL)
		printf("f5 is NULL\n");

	return 0;
}
