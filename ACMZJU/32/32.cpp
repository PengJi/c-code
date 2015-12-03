//string��������ֵ�໥ת��

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

	//����ֵת��Ϊstring��C����
	char b[10];
	string a;
	sprintf(b,"%d",1975);
	a=b;
	cout<<a<<endl;

	//��ֵת��Ϊstring
	string cc=convertToString(1976);
	cout<<cc<<endl;

	//stringת��Ϊ��ֵ
	string dd="2006";
	int p=convertFromString(dd)+2;
	cout<<p<<endl;

	return 0;

}