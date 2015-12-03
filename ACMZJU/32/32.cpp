//string对象与数值相互转换

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string convertToString(double x){
	ostringstream o;
	if(o << x)
		return o.str();
	return "conversion error";
}

double convertFromString(const string &s){
	istringstream i(s);
	double x;
	if(i >> x){
		return x;
	}
	return 0.0;
}

int main(){

	//将数值转换为string，C方法
	char b[10];
	string a;
	sprintf(b,"%d",1975);
	a=b;
	cout<<a<<endl;

	//数值转换为string
	string cc=convertToString(1976);
	cout<<cc<<endl;

	//string转换为数值
	string dd="2006";
	int p=convertFromString(dd)+2;
	cout<<p<<endl;

	return 0;

}