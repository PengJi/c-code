#include <iostream>
#include <memory>
#include <string>

using namespace std;

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

	void setStr()(string s){
		str = s;
	}
	void print(){
		cout<<str<<endl;
	}
private:
	string str;
}


