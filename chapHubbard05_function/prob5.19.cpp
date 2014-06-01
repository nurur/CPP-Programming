// Problem 5.19, chapter 5 (C++, J. R. Hubbard) 
// Euclidean Algorithms (Least Common Multiple)

 
#include <iostream>
using namespace std;


int algorithmEuclid(int m, int n)
{
  int t;
  int i, j;
  i = m; j = n;

  for ( ; n>0; )
    {
      t = m % n;
      m = n;
      n = t;	
    } 

  int lcm = j * i/m;
  return lcm;
}



int main()
{
  int i, j, k, m, n;
  cout << "Provide the integer numbers : "; 
  cin >> m >> n;

  j = m; k = n;    // Copy integers
  
  int lcm = algorithmEuclid(m, n);
  cout << "The least common multiple of   " 
       << "(" << j << ", " << k << ") is: " 
       << lcm << endl;
  
  return 0;
}
