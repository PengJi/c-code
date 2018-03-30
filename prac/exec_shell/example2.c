#include<stdio.h>

int main()
{  
	char buffer[80];  
	FILE  *fp=popen("bash /home/book/shell/test.sh","r");  
	fgets(buffer,sizeof(buffer),fp);

	printf("%s",buffer);
	pclose(fp);  

	return 0;  
}
