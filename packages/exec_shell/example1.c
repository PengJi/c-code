#include <stdio.h>    
#include <string.h>
#include <errno.h>

int main(int argc,char*argv[]){    
    FILE *fstream=NULL;      
    char buff[1024];    
    memset(buff,0,sizeof(buff));    
    if(NULL==(fstream=popen("ifconfig","r")))      
    {     
        fprintf(stderr,"execute command failed: %s",strerror(errno));      
        return -1;      
    }     
    while(NULL!=fgets(buff, sizeof(buff), fstream)) {  
            printf("%s",buff);    
    }  
    pclose(fstream);    
    return 0;     
}
