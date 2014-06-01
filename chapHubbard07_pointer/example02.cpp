// EXAMPLE 7.8
// Returning a reference by a function 

#include <iostream>
using namespace std;


int& max(int& m, int& n)
{
  return (m > n ? m : n);
}
 


int main()
{
  int m = 44, n = 22;
  cout << "m = " << m << ", n = " << n << endl;
  
  max(m,n) = 55; // Changes the value of m from 44 to 55;
  cout << "m = " << m << ", n = " << n << endl;

  return 0;
}
