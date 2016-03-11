#include <stdio.h>

/*
 * http://www.cnblogs.com/qytan36/archive/2010/09/27/1836569.html
 */

void f(unsigned char v)
{
    char c = v;
    unsigned char uc = v;
    unsigned int a = c, b = uc;
    int i = c, j = uc;
    printf("----------------\n");
    printf("%%c: %c, %c\n", c, uc);
    printf("%%X: %X, %X\n", c, uc);
    printf("%%u: %u, %u\n", a, b);
    printf("%%d: %d, %d\n", i, j);
} 

int main(int argc, char *argv[])
{
    f(0x80);
    f(0x7F); 
    return 0;
}
