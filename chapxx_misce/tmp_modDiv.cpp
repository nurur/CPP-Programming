// Example: Recursive Function
// Recusive Void Function: finding facotrial function 

#include <cstdlib>
#include <iostream>
using namespace std;


void reverse (int num)
{
  if (num < 10)
    { 
      cout << num;
    } 
  else 
    { cout << (num%10) << "";
      reverse (num/10);
    }
}





int main()
{

  reverse(3456); // Printing Reverse
  cout << endl;

  int i = 74 % 60;
  int j = 74 / 60;
  cout << i << " " << j << endl;
  cout << endl;

  int k = 37 % 60;
  int l = 37 / 60;
  cout << k << " " << l << endl;

  cout << endl;
  return 0;
}
