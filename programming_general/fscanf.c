#include <iostream>
#include <stdio.h>

/*
 * C++用fscanf（）函数读取TXT文件内容
 * http://blog.csdn.net/sinat_24310873/article/details/53141429
 */

int main(void){
FILE  *fq;
double x[10], y[10], z[10];

fq=fopen("step.dat" ,"rt+");//"rt+"是打开一个文本文件，可以读写。
for (int i=1; i<=10; i++){
fscanf(fq,"%lf ,%lf ,%lf\n",&x[i], &y[i], &z[i]);//%lf之间应该有逗号，因为没有逗号只能读第一个数。用&是因为要把数存到对应数组元素的地址中去。\n是换行读取
}
fclose(fq);
return 0;
}
