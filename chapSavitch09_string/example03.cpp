// Example: 
// Self-Test exercise 9.15, 9.16, 9.17
// get & put function 


#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;



void newline()
{ 
  char symbol;
  do
    {
      cin.get(symbol);
    } while(symbol != '\n');
}



int main()
{
  
  char nextSymbol;
  cin.get(nextSymbol);
  cout << nextSymbol << endl;
  newline();

  //check 
  char c1, c2, c3, c4;
  cout << "Enter a line of input:\n";
  cin.get(c1);
  cin.get(c2);
  cin.get(c3);
  cin.get(c4);

  cout << "c1 :" << c1 << " c2:" << c2 << " c3:" << c3 
       << " c4:" << c4 << endl;
  newline();
  cout << endl;
  

  //check
  char next;
  int count = 0;
  cout << "Enter a line of input:\n";
  cin.get(next);

  while (next != '\n') 
    {
      if ( (count%2) == 0) cout << next;
      count++;
      cin.get(next); 
      //cin >> next;  // an infinite loop 
    }
  

  cout << endl;
  return 0;
}
