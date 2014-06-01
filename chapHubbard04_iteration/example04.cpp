// Example : 4.12
// Factorial Numbers : using for loop


#include <iostream>
using namespace std;


int main()
{
  long bound;
  cout << "Enter ant positive number(>1): ";
  cin >> bound;
  cout << "Factorial numbers " << bound << " :\n1, 1";

  long f=1;
  for (int i=2; i<=bound; i++)
    f *= i;
  cout << ", " << f; 
  
  cout << endl;
  return 0;
}
