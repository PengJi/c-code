#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Test
{
public:
    Test(string s)
    {
        str = s;
       cout<<"Test creat\n";
    }
    ~Test()
    {
        cout<<"Test delete:"<<str<<endl;
    }
    string& getStr()  // 返回引用
    {
        return str;
    }
    void setStr(string s)
    {
        str = s;
    }
    void print()
    {
        cout<<str<<endl;
    }
private:
    string str;
};

int main(){
	auto_ptr<Test> ptest(new Test("123"));
	ptest->setStr("hello");
	ptest->print();
	ptest.get()->print();  // 成员函数，返回原始指针
	ptest->getStr() += "world";
	(*ptest).print();
	ptest.reset(new Test("1234"));  // 成员函数，重新绑定指定的对象，调原对象的析构函数
	ptest->print();

	auto_ptr<Test> ptest2(new Test("456"));
	ptest2->print();
	ptest2 = ptest;  // 调用原对象的析构函数
	ptest2->print();
	if(ptest.get()==NULL)  // 赋值以后，原指针变为空
		cout<<"ptest == NULL\n";
	
	ptest2.release();  // 把智能指针赋为空，它指向的内存并没有被释放

	return 0;
}
