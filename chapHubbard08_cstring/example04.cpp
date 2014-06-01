// EXAMPLE: 8.6 
// cin.get() function


#include <iostream>
using namespace std;


int main ()
{
  char ch;
  int count = 0;

  while (cin.get(ch))
    { 
      if (ch == 'e') ++count;
      cout << "total number of e's are counted: " << count << endl;
    }
    
  return 0;
}

