#include <iostream>
#include <memory>
#include <string>

using namespace std;

/*
 * unique_ptr可实现如下功能：
 * 1. 为动态申请的内存提供异常安全
 * 2. 将动态申请的内存所有权传递给某函数
 * 3. 从某个函数返回动态申请内存的所有权
 * 4. 在容器中保存指针
 * 5. auto_ptr应该具有的功能
 */

class Test
{
public:
	Test(string s){
		str = s;
		cout<<"Test create"<<endl;
	}

	~Test(){
		cout<<"Test delete: "<<str<<endl;
	}

	string &getStr(){
		return str;
	}

	void setStr(string s){
		str = s;
	}
	void print(){
		cout<<str<<endl;
	}
private:
	string str;
};

unique_ptr<Test> fun(){
	return unique_ptr<Test>(new Test("789"));
}

int main(){
	unique_ptr<Test> ptest(new Test("123"));
	unique_ptr<Test> ptest2(new Test("456"));
	ptest->print();
	ptest2 = std::move(ptest); //不能直接ptest2=ptest
	if(ptest == NULL)
		cout<<"ptest=NULL"<<endl;

	Test *p = ptest2.release();
	p->print();
	ptest.reset(p);
	ptest->print();
	ptest2 = fun(); //可以用=，使用了移动构造函数
	ptest2->print();

	return 0;
}

/**
 * 编译
 * g++ unique_ptr.cpp -std=c++11
 * 
 * 输出:
 * Test create
 * Test create
 * 123
 * Test delete: 456
 * ptest=NULL
 * 123
 * 123
 * Test create
 * 789
 * Test delete: 789
 * Test delete: 123
 */
