// Example: 9.1, 9.2, 9.3
// reading one 'character' at a time from a line 
// consisting of several strings 

// typical input: cognito, ergo sum!


#include <cstring>
#include <string>
#include <iostream>
using namespace std;



int main()
{
  //check
  //char c1, c2;
  //cin.get(c1);
  //c2 = tolower(c1);
  //cout << c2 << endl;

  //check
  char c;

  cout << "Enter a line of strings: ";
  while ( cin.get(c) )
    {
      //if (c >= 'a' && c <= 'z') c += 'A'-'a';
      if ( islower(c) ) c = toupper(c);
      cout.put(c);

      if (c == '\n') break;
    }
  
  return 0;
}
