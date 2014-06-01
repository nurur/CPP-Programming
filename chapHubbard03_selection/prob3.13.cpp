// Problem 3.13, chapter 3 (C++, J. R. Hubbard) 
// Program reads an integer and writes the sum of its digits
 

#include <iostream>
using namespace std;


int main()
{
  int i, j, k, m, length, sum;
  cout << "Provide the integer : "; 
  cin >> m;
  cout << "Provide the number of digits in the integer: ";
  cin >> length;

  sum = 0;
  for (i=0; i<length; i++)
    {
      j = m % 10;
      k = m / 10;
      m = k;
      sum += j;
    }

  cout << "Sum of the digits is: " << sum << endl;
  return 0;
}
