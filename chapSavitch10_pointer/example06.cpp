// Example : 
// Pointers Arithmatic  and sizeof Operator
// Note:
// Pointer arithmatic is an arithmatic of addresses. 
// It not an arithmatic of numbers. 
// This arithmatic gives an way to manipulate arrays.  
//
//*When the sizeof operator is applied to a 'static array', 
// it yields the total number of bytes in that array, 
// not the size of the pointer represented by the array identifier.
//*When the sizeof operator is applied to a 'dynamic array', 
// it yields the total number of bytes of the pointer represented 
// by the array identifier.


#include <iostream>
using namespace std;


typedef double* doublePtr;


int main()
{
  // Dynamic array 
  doublePtr a = new double[10];
  doublePtr b = new double[10];

  for (int i=0; i<10; i++)    
    a[i] = 1.0;

  for (int i=0; i<10; i++)    
    cout << a[i] << " ";

  // Static array 
  double c[10] = {0,1,2,3,4,5,6,7,8,9};


  // Pointer arithmatic 
  int n;
  a + n;
  b + n;
  a - b;

  cout << sizeof(a) << " " << sizeof(b) << endl;
  cout << sizeof(c) << endl;


  delete[] a;
  delete[] b;

  return 0;
}
