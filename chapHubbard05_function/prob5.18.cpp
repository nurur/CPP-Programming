// Problem 5.18, chapter 5 (C++, J. R. Hubbard) 
// Euclidean Algorithms (Greatest Common Divisor)

 
#include <iostream>
using namespace std;


int algorithmEuclid(int m, int n)
{
  int t;
  for ( ; n>0; )
    {
      t = m % n;
      m = n;
      n = t;	
    } 
  return m;
}



int main()
{
  int i, j, k, m, n;
  cout << "Provide the integer numbers : "; 
  cin >> m >> n;

  j = m; k = n;    // Copy integers
  
  int gcd = algorithmEuclid(m,n);
  cout << "The greatest common divisor of " 
       << "(" << j << ", " << k << ") is: " 
       << gcd << endl;
  
  return 0;
}
