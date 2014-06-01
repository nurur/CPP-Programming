// Problem 7.8, chap 7 (C++, J R Hubbard)


#include <iostream>
using namespace std;



unsigned length(const char* s)
{
  unsigned len = 0;

  const char* p= s;
  for (p; *p !='\0'; p++)
    len++;
  
  //for (s; *s !='\0'; s++)
  //  len++;
  
  //while (s[len] != '\0') 
  //  len++; 
  return len;
}




int main ()
{
  const char* s = "Dr Nurur Rahman";
  unsigned len  = length(s);
  cout << "The number of bytes is : " << len << endl;

  return 0;
}
