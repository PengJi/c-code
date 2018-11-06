//sscanf函数

#include <string>
#include <iostream>

using namespace std;

int main(){
	string s1,s2,s3;
	char sa[100],sb[100],sc[100];

	sscanf("abc 123 bcd","%s %s %s",sa,sb,sc);//分隔符为空格
	s1=sa;
	s2=sb;
	s3=sc;

	cout<<s1<<" "<<s2<<" "<<s3<<endl;

	int a,b,c;
	sscanf("1 2 3","%d %d %d",&a,&b,&c);
	cout<<a<<" "<<b<<" "<<c<<endl;

	int x,y,z;
	sscanf("4,5$6","%d,%d$%d",&x,&y,&z);
	cout<<x<<" "<<y<<" "<<z<<endl;

	return 0;

}