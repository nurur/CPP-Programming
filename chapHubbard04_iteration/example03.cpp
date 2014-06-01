// Example : 4.9
// Factorial Numbers : using do-while loop


#include <iostream>
using namespace std;


int main()
{
  long bound;
  cout << "Enter ant positive number(>1): ";
  cin >> bound;
  cout << "Factorial numbers " << bound << " :\n1, 1";

  long f=1, i=1;
  //long j=2;
  do
    {
      f *= ++i;
      cout << ", " << f; 
      //j++;
    } while(i < bound);
  
  cout << endl;

  return 0;
}
