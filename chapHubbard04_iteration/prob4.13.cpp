// Problem 4.13, chapter 3 (C++, J. R. Hubbard) 
// Integer square root of a given number


#include <iostream>
using namespace std;


int square(int n)
{ return n*n; }


int main()
{
  long i, m, n;
  cout << "Provide the integer number : "; 
  cin >> m;

  for (i=1; i<10000; i++)
    if (m == square(i)) 
      { n = i; break; }
    else if (m > square(i) && m < square(i+1))
      { n = i; break; }
  
  cout << "The integer square root of "<< m << " is " 
       << n << endl;

  return 0;
}
