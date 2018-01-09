#include <stdio.h>

/*
通过函数调用的其他形式
http://c.biancheng.net/cpp/html/496.html
*/
void MyFun(int x);
void (*FunP)(int );/* 声明一个用以指向同样参数，返回值函数的指针变量。 */

int main(int argc, char* argv[])
{
   MyFun(10); /* 这里是调用MyFun(10)函数 */
   FunP = MyFun; /* 将MyFun函数的地址赋给FunP变量 */
   FunP(20); /* （★）这是通过函数指针变量来调用MyFun函数的。*/
   return 0;
}

//还有以下形式的调用
void MyFun(int x) //这里定义一个MyFun函数
{
   printf("%d\n",x);
}

int main(int argc, char* argv[])
{
   MyFun(10); /* 这里是调用MyFun(10)函数 */
   FunP = &MyFun; /* 将MyFun函数的地址赋给FunP变量 */
   FunP(20); /* 这是通过函数指针变量来调用MyFun函数的。 */
   return 0;
}

int main(int argc, char* argv[])
{
   MyFun(10); /* 这里是调用MyFun(10)函数 */
   FunP = MyFun; /* 将MyFun函数的地址赋给FunP变量 */
   (*FunP)(20); /*这是通过函数指针变量来调用MyFun函数的。*/
   return 0;
}

int main(int argc, char* argv[])
{
   (*MyFun)(10); /*看，函数名MyFun也可以有这样的调用格式*/
   return 0;
}
