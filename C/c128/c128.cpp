//ÒëÃÜÂë
#include <stdio.h>
int main(){
	char c[50],c1;
	int i=0;
	printf("ÇëÊäÈëÒ»ĞĞ×ÖÄ¸:\n");
	scanf("%s",c);
	while(c[i]!='\0'){
		if((c[i]+4)>90 && c[i]<91){
			c[i]=c[i]+4-25;
			printf("%c",c[i]);
		}
		if((c[i]+4)>122 && c[i]<123){
			c[i]=c[i]+4-25;
			printf("%c",c[i]);
		}
		printf("%c",c[i]+4);
		i++;
	}
	printf("\n");

	return 0;
}