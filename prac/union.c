#include <stdio.h>
int main(){
int a,b;
struct Mem3Block {
  union {       
    struct {
      int prevSize;  
      int size4x;   
    } hdr;    
    struct {
      int next;     
      int prev;    
    } list;   
  } u;   
} Mem3Block;


a = sizeof(int);
b = sizeof(Mem3Block);

printf("%d\n",a); 
printf("%d\n",b);

return 0;

}
