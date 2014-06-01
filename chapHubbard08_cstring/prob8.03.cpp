// PROBLEM: 8.03
// strcat()



#include <cstring>
#include <string>
#include <iostream>
using namespace std;


char* stringCat(char* s1, const char* s2)
{
  char* end = s1;

  // find the last character of s1;  
  for (end; *end; end++)
    { cout << ""; }

  // find the size of s2
  const char* p;
  p = s2;
  int size = 0;
  for (p; *p; p++)
    size++;

  // concate s2 to s1
  const char* q;
  q = s2;
  for (q; *q && (q-s2 < size); )
    *end++ = *q++;

  *end = '\0';
  return s1;
}



int main ()
{
  char c1[9] = "ABCDEFGH";
  char c2[4] = "UVW";
  cout << "Before string-copy, c1 & c2 : " << c1 << ", " << c2 << endl; 

  stringCat(c1,c2);
  cout << "After string-concat,c1 & c2 : " << c1 << ", " << c2 << endl; 

  return 0;
}
