// Problem 7.22, chap 7 (C++, J R Hubbard)
// Pointer to Function 


#include <iostream>
using namespace std;


int productFunc(int k)
{ return k; }


int product( int (*pf)(int k), int n )
{
  int i, p;

  p=1;
  for(i=1; i<=n; i++)
    {    
      p *= (*pf)(i);
      cout << p << endl;
    }

  return p;
}


int main()
{
  long m;
  m = product(productFunc, 3);
  cout << "Calling product function  : " << m << endl;

  return 0;
}
