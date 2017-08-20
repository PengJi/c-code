#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(){
	stringstream stream;
	int n;
	string str;

	// string 转 int
	stream << "123";  // 向stream中插入字符串"123"
	stream >> n;  // 从stream中提取刚插入的字符串"123"，并将其赋予变量n，完成转换
	cout << n << endl;  // 输出n

	stream.clear();

	// int 转 string
	stream << 123;  //向stream中插入整数123
	stream >> str;  //从stream中提取刚插入的整数，并赋予变量str,完成转换
	cout << n << endl;

	stream.clear();

	//以上方法在处理大数据量的时候速度较慢,sprintf和sscanf速度相对较快
	
	//int转string
	char cstr[10];
	int a = 10;
	sprintf(cstr,"%d",a);
	str = cstr;
	cout << str << endl;

	//string 转 int 
	sscanf(cstr,"%d",&a);
	cout << a << endl;

	return 0;
}
