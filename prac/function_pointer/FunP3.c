#include <stdio.h>

/*
函数指针作为某个函数的参数
我要设计一个CallMyFun函数，这个函数可以通过参数中的函数指针值不同来分别调用MyFun1、MyFun2、MyFun3这三个函数（注：这三个函数的定义格式应相同）。
http://c.biancheng.net/cpp/html/496.html
*/

void MyFun1(int x);
void MyFun2(int x);
void MyFun3(int x);

typedef void (*FunType)(int ); /* ②. 定义一个函数指针类型FunType,与①函数类型一致 */
void CallMyFun(FunType fp,int x);

int main(int argc, char* argv[]){
   CallMyFun(MyFun1,10); /* ⑤. 通过CallMyFun函数分别调用三个不同的函数 */
   CallMyFun(MyFun2,20);
   CallMyFun(MyFun3,30);
}

void CallMyFun(FunType fp,int x){ /* ③. 参数fp的类型是FunType。*/
   fp(x);/* ④. 通过fp的指针执行传递进来的函数，注意fp所指的函数是有一个参数的。 */
}

void MyFun1(int x){ /* ①. 这是个有一个参数的函数，以下两个函数也相同。 */
   printf("函数MyFun1中输出：%d\n",x);
}

void MyFun2(int x){
   printf("函数MyFun2中输出：%d\n",x);
}

void MyFun3(int x){
   printf("函数MyFun3中输出：%d\n",x);
}
