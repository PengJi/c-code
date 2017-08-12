/* pow example */
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */

void f(int *m){
	*m=5;
}

int main ()
{
  printf ("7 ^ 3 = %f\n", pow (7.0, 3.0) );
  printf ("4.73 ^ 12 = %f\n", pow (4.73, 12.0) );
  printf ("32.01 ^ 1.54 = %f\n", pow (32.01, 1.54) );

  int n = 1;
  int *k = &n;
  printf("%d\n",n);
  printf("%d\n",*k);
  f(&n);
  f(k);
  printf("%d\n",n);
  printf("%d\n",*k);

  return 0;
}
