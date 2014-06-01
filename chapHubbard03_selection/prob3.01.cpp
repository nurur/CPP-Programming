// Problem 3.1, chapter 3 (C++, J. R. Hubbard) 


#include <iostream>
using namespace std;



int main ()
{
  int m, n;
  cout << "Enter two positive intergers: ";
  cin >> m >> n;


  if (m%n) 
    cout << m << " is not divisible by " << n << endl;

  if ( !(m%n) ) 
    cout << m << " is divisible by " << n << endl;

  if (m%n ==0) 
    cout << m << " is divisible by " << n << endl;


  return 0;
}
