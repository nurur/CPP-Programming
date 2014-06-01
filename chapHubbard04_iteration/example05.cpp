// Example 4.23
// The continue statement 
// Infinite while loop, Infinite for loop


#include <iostream>
using namespace std;



int main()
{
  int m, n;

  cout << "Program uses infinite while loop ...\n";
  while(true)
    {
      cout << "Enter an integer: "; cin >> m;
      if (m%2 == 0) continue;
      if (m%3 == 0) break;
      cout << "Bottom of the loop" << endl;
    }
  cout << "Outside of the loop" <<endl;
  cout << endl;
  


  cout << "Program uses infinite for loop ... \n";
  for( ; ; )
    {
      cout << "Enter an integer: "; cin >> n;
      if (n%2 == 0) continue;
      if (n%3 == 0) break;
      cout << "Bottom of the loop" << endl;
    }  
  cout << "Outside of the loop" <<endl;

  return 0;
}
