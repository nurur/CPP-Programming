// Problem 4.11, chapter 3 (C++, J. R. Hubbard) 
// Program reads an integer and reverses its digits
 

#include <iostream>
using namespace std;


int main()
{
  int i, j, k, m, length;
  cout << "Provide the integer : "; 
  cin >> m;
  cout << "Provide the number of digits in the integer: ";
  cin >> length;

  int digits[length];
  for (i=0; i<length; i++)
    {
      j = m % 10;
      k = m / 10;
      m = k;
      digits[i]= j;
    }
  
  cout << "The new integer is  : ";
  for (i=0; i<length; i++)
    cout << digits[i];
  cout << endl;


  return 0;
}
