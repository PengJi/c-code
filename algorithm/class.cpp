#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class parent  
{  
    public:  
    virtual void output();  
};  
void parent::output()  
{  
    printf("parent!");  
}  
       
class son : public parent  
{  
    public:  
    virtual void output();  
};  
void son::output()  
{  
    printf("son!");  
}

int main(){
	son s; 
	memset(&s , 0 , sizeof(s)); 
	parent& p = s; 
	p.output();
}
