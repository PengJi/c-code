#include <stdio.h>

/*
 * 通过函数指针变量调用函数
 * http://c.biancheng.net/cpp/html/496.html
 */

void MyFun(int x); /* 这个声明也可写成：void MyFun( int )*/
void (*FunP)(int); /*也可声明成void(*FunP)(int x)，但习惯上一般不这样。 */

int main(int argc, char* argv[])
{
   MyFun(10); /* 这是直接调用MyFun函数 */
   FunP = &MyFun; /* 将MyFun函数的地址赋给FunP变量 */
   (*FunP)(20); /* （★）这是通过函数指针变量FunP来调用MyFun函数的。 */
}

void MyFun(int x) /* 这里定义一个MyFun函数 */
{
   printf("%d\n",x);
}
