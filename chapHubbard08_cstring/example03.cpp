// EXAMPLE: 8.4, 8.5 
// cin member function : cin.getline()


#include <iostream>
using namespace std;

int main ()
{

  // check 
  char word[80];

  do
    { cin >> word;
      if (*word) cout << "[" << line << "]" << endl;
    } while (*word);
    c
  


  // check 
  char line[80];

  do
    { cin.getline(line,len,',');
      if (*line) cout << "[" << line << "]" << endl;
    } while (*line);
    
  return 0;
}

