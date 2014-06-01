// Problem 4.12, chapter 3 (C++, J. R. Hubbard) 
// Babylonian Algorithms to find square root of 2


#include <iostream>
using namespace std;


int main()
{
  int lim;
  float m, n;

  n   = 2.;
  lim = 10;
  for (int i=0; i<lim;i++)  
    n = (n + 2/n)/2; 
  
  cout << "Babylonian algorithm ... " << endl;
  cout << "The square root of 2 is: " << n << endl;

  return 0;
}
