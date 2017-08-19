#include <iostream>
#include <memory>
#include <string>

using namespace std;

/*
 * weak_ptr是用来解决shared_ptr相互引用时的死锁问题。
 * 如果两个shared_ptr相互引用，那么这两个指针的引用计数永远不可能下降为0，
 * 资源永远不会释放。
 *
 */

class B;

class A{
public:
	//shared_ptr<B> pb1;  // 两个对象的引用都为2，无法释放
	weak_ptr<B> pb1;  // 两个对象能够得到释放
	~A(){
		cout<<"A delete"<<endl;
	}
};

class B{
public:
	shared_ptr<A> pa1;
	~B(){
		cout<<"B delete"<<endl;
	}
};

void fun(){
	shared_ptr<B> pb(new B());
	shared_ptr<A> pa(new A());

	pb->pa1 = pa;
	pa->pb1 = pb;

	cout<<pb.use_count()<<endl;
	cout<<pa.use_count()<<endl;
}

int main(){
	fun();

	return 0;
}
