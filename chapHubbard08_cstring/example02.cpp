// EXAMPLE: 8.3 
// Ordinary Input and Output of C-Strings 

#include <iostream>
using namespace std;


int main ()
{
  const int n = 5;
  char word[80];

  cout << "Enter a group of character: "; 
  do
    { cin  >> word;
      if (*word) cout << "\"" << word << "\"" << endl;
    } while (*word);
    
  return 0;
}

