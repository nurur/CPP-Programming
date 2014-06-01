// EXAMPLE 7.10: 
// Traversing array with pointer 


#include <iostream>
using namespace std;


int main ()
{
  const int SIZE = 9;
  int  a[SIZE] = {11,22,33,44,55,66,77,88,99};

  cout << "a  = " << a << ", &a = " << &a << ", *a = " << *a << endl;
  cout << endl;


  cout << "sizeof(short)  = " << sizeof(short) << endl;
  cout << "sizeof(int)    = " << sizeof(int)   << endl;
  cout << "sizeof(long)   = " << sizeof(long)  << endl;
  cout << endl;
  

  int* end = a + SIZE;
  cout << end << "  " << &end << " " << *end << endl;

  int* p = a;
  for (p; p < end; p++)
    { 
      cout << "p, &p, *p : " << p << " " << &p << " " << *p << endl;
    }
  

  cout << endl;
  return 0;
}
