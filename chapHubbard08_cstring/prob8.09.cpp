// PROBLEM: 8.09
// number of occurences of a given character in a C-string  


#include <cstring>
#include <string>
#include <iostream>
using namespace std;



int numberChar(const char* s, int c)
{ 
  int n = 0;
  const char* p = s;

  // search 'c' within 's'
  // increase the counter, if 'c' is within 's'
  for (p; p && *p; p++)    
    if (*p == c) n++; 
  
  // return the counter
  return n;
}



int main ()
{
  char* s = "Hello World!, This is Nurur Rahman";
  char  c = 'l';
  int   n = numberChar(s,c);
  cout << "the number of occurence of " << c << " is: "<< n << endl;



  return 0;
}
