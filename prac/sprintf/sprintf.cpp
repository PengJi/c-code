#include <iostream>

using namespace std;

int main(){
	char str[256] = { 0 };
    int data = 1024;

    //��dataת��Ϊ�ַ���
    sprintf(str,"%d",data);
	printf("�ַ�����%s\n",str);

    //��ȡdata��ʮ������
    sprintf(str,"0x%X",data);
	printf("ʮ�����ƣ�%s\n",str);

    //��ȡdata�İ˽���
    sprintf(str,"0%o",data);
	printf("�˽��ƣ�%s\n",str);

    const char *s1 = "Hello";
    const char *s2 = "World";

    //�����ַ���s1��s2
    sprintf(str,"%s %s",s1,s2);
	printf("�����ַ�����%s\n",str);

	return 0;
}