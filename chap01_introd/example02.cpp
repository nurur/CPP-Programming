// arithmetic operation in C++

#include <iostream>
using namespace std;


int main ()
{
  /*integer  arithmatic*/
  int m, n;
  m=27;
  n=3;
  cout << "modules, m%n = " << m%n << endl;

  m=54;
  n=20;
  cout << "modules, m%n = " << m%n << endl;


  /*increment */
  /*pre-increment*/
  int a, b;
  a = 4;
  b = ++a;
  cout << "integers a & b = " << a << ',' << b << endl;
  

  /*post-increment*/
  b = a++;
  cout << "integers a & b = " << a << ',' << b << endl;
  cout << endl;

  a *= b++;
  cout << "a *=b++ : " << a << ',' << b << endl;
  /* a *= ++b; */
  /* cout << "a *=b++ : " << a << ',' << b << endl; */

  int m1,n1;
  m1 = 2;
  n1 = 100 + m1++;
  cout << m1 << ',' << n1 << endl;
  
  return 0;
}
