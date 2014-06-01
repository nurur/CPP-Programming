// PROBLEM: 8.02
// strcpy(), strncpy()



#include <cstring>
#include <string>
#include <iostream>
using namespace std;


char* stringCopy(char* s1, const char* s2)
{
  char* p = s1;
   
  // method 1
  do
    {
      *p++ = *s2++;
    } while (*s2);
  *p = '\0';              // add null character   
  
  // method 2
  //for (s1; *s2; )
  //  { *p++ = *s2++; }
  //*p = '\0';              // add null character

  return s1;
}



char* stringNCopy(char* s1, const char* s2, int n)
{
  char* p = s1;
  int i   = 0;

  // method 1
  do 
    { 
      *p++ = *s2++;
      i++;
    } while( i < n );
  
  // method 2
  //for (p; *s2 && i < n; )
  //  { *p++ = *s2++; 
  //    i++;
  //  }
  
  return s1;
}




int main ()
{
  char c1[9] = "ABCDEFGH";
  char c2[3] = "UV";
  cout << "Before string-copy, c1 & c2 : " << c1 << ", " << c2 << endl; 

  stringCopy(c1,c2);
  cout << "After string-copy,  c1 & c2 : " << c1 << ", " << c2 << endl; 


  char c3[9] = "ABCDEFGH";
  char c4[2] = "W";
  stringNCopy(c3,c4,4);
  cout << "After string-copy,  c3 & c4 : " << c3 << ", " << c4 << endl; 


  return 0;
}
