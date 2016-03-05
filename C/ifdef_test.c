#include <stdio.h>

#define MACRO1
#define MACRO2

int main(void)
{
#ifdef MACRO1 // test whether MACRO1 is defined...
    printf("\nMACRO1 Defined\n");
#endif

#ifdef MACRO2 // test whether MACRO2 is defined...
    printf("\nMACRO2 Defined\n");
#endif
    return 0;
}
