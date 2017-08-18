#include <iostream>
#include <string>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

/*
 * 数组与指针的区别
 */

void func(char a[10]){
	cout<<sizeof(a)<<endl;
}

//分配内存
char *getMemory(int num){
	char *p = (char*) malloc(sizeof(char) *num);
	return p;
}

void testMemory(void){
	char *str = NULL;
	str = getMemory(10);

	strcpy(str,"hello getMemory");
	cout<<str<<endl;
	free(str);
}

char *getString(void){ //返回执行栈内存的指针,编译器出现警告
	char p[] = "hello getString";
	return p;
}

void testString(void){
	char *str = NULL;
	str = getString();
	cout<< str<<endl;

}

char *getString2(void){
	char *p = "hello getString2";  // 字符串常量
	return p;
}

void testString2(){
	char *str = NULL;
	str = getString2();
	cout << str <<endl;
}

int main(){
	//1.修改内容
	char a[] = "hello";
	a[0] = 'x';
	cout<<a << endl;
	
	char *p = "world";  //p指向常量字符串
	//p[0] = 'x'; //编译器出现警告
	cout<<p<<endl;

	//2.内容复制与比较
	char b[10];
	strcpy(b,a); //不能用b=a
	if(strcmp(a,a)==0) cout<<"strcmp"<<endl;

	int len = strlen(a);
	p = (char*) malloc(sizeof(char)*(len+1));
	strcpy(p,a);
	if(strcmp(p,a)==0) cout<<"strcmp"<<endl;

	//当数组作为函数的参数进行传递时，数组自动退化为同类型的指针。
	func(b);

	testMemory();
	testString();
	testString2();
}

