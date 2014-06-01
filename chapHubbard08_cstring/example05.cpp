// EXAMPLE: 8.7 
// cout.put() function
// text: fourscore and seven years ago our father


#include <iostream>
using namespace std;


int main ()
{
  char ch;
  char pre = '\0';  //initialize 'pre'

  while (cin.get(ch))
    { 
      if (pre == ' ' || pre == '\n') cout.put(char(toupper(ch)));
      else cout.put(ch);

      pre = ch; // change 'pre' to the previously read character
    }
    
  return 0;
}

