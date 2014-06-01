// Problem 4.14, chapter 4 (C++, J. R. Hubbard) 
// Euclidean Algorithms 

 
#include <iostream>
using namespace std;


int main()
{
  int i, j, k, m, n;
  cout << "Provide the integer numbers : "; 
  cin >> m >> n;

  j = m; k = n;

  while( n>0 )
    {
      i = m % n;
      m = n;
      n = i;	
    } 
  cout << "The greatest common divisor of " 
       << "(" << j << ", " << k << ") is: " 
       << m << endl;
  
  return 0;
}
