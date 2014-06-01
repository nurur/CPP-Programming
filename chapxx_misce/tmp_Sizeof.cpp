// Example: Sizeof operator for Character String
// Note: 
// The syntax "const char s[] only means ‘an array’ when it is NOT a 
// function argument. When it is a function argument, it is the same 
// as saying "const char* s", even if one specifies a dimension.


//#include <cstdio>
#include <iostream>
using namespace std;


void f1(const char s[])
{ cout << "The size of f()'s     s is : " << sizeof(s) << endl; }

void f2(const char* s)
{ cout << "The size of f()'s     s is : " << sizeof(s) << endl; }




int main()
{
  cout << "s is declared as a const array   : " << endl;
  const char s1[] = "Hello World!";
  cout << "const char s[] = " << s1 << endl;
  cout << "The size of main()'s  s is : " << sizeof(s1)  << endl;
  f1(s1);
  cout << "The size of main()'s &s is : " << sizeof(&s1) << endl;
  cout << endl;


  cout << "s is declared as a const pointer : " << endl;
  const char* s2 = "Hello World!";
  cout << "const char* s = " << s2 << endl;
  cout << "The size of main()'s  s is : " << sizeof(s2)  << endl;
  f2(s2);
  cout << "The size of main()'s &s is : " << sizeof(&s2) << endl;


  char  c[] = "C++ programing";
  char*  d  = "C++ programing";
  string e  = "C++ programing";
  cout << sizeof(c) << " " << sizeof(d)  << " " << sizeof(e);
  cout<< endl;

  for (int i=0; i < sizeof(c); i++)
    cout << c[i];
  cout<< endl;

  char question[] = "Please, enter your first name: ";
  char greeting[] = "Hello, ";
  char yourname [80];
  cout << question;
  cin >> yourname;
  cout << greeting << yourname << "!";

  return 0;
}
