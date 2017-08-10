#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    printf("\n");
    int a[5] = {1, 2, 3, 4, 5};
    int *p, **k;
    p = a;
    k = &p;
    printf("%d", *(p++));
    printf("%d", **k);
    return 0;
}
