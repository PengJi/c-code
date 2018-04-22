#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/*
 * c_str()生成一个const char* 指针，指向以空字符终止的数组
 */

int main ()
{
  std::string str ("Please split this sentence into tokens");

  char * cstr = new char [str.length()+1];
  std::strcpy (cstr, str.c_str());

  // cstr now contains a c-string copy of str

  char * p = std::strtok (cstr," ");
  while (p!=0)
  {
    std::cout << p << '\n';
    p = std::strtok(NULL," ");
  }

  delete[] cstr;

  char* c = new char[20];
  string s = "123";

  strcpy(c,s.c_str());
  cout << c << endl;
  s="abc";
  cout << c << endl;

  return 0;
}
