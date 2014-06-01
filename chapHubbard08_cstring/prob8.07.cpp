// PROBLEM: 8.07 
// cin member function : cin.getline()
// Revised from of EXAMPLE 8.4 and 8.5

// typical text: George Washington, John Adams, Thomas Jeferson 



#include <iostream>
using namespace std;

int main ()
{
  char word[80];

  while (cin >> word)
    { 
      if (*word) cout << "[" << word << "]" << endl;
    }
  
  return 0;
}

