#include <stdio.h>

/*
定义一个函数指针类型，然后再用这个类型来声明函数指针变量
首先，在void (*FunType)(int)前加了一个typedef 。这样只是定义一个名为FunType函数指针类型，而不是一个FunType变量。
然后，“FunType FunP;”这句就如“PINT px;”一样地声明一个FunP变量。
http://c.biancheng.net/cpp/html/496.html
*/

void MyFun(int x); /*此处的声明也可写成：void MyFun( int )*/
typedef void (*FunType)(int); /*（★）这样只是定义一个函数指针类型*/

FunType FunP; /*然后用FunType类型来声明全局FunP变量*/

int main(int argc, char* argv[]){
   FunType FunP; /*函数指针变量当然也是可以是局部的 ，那就请在这里声明了。 */
   MyFun(10);
   FunP = &MyFun;
   return 0;
}

void MyFun(int x){
   printf("%d\n",x);
}
