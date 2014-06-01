// EXAMPLE:
// Swap Function 
// With Pointer variable 


#include <iostream>
using namespace std;


void swapping(int *ptr_c, int *ptr_d)
{
  int tmp;
  
  tmp    = *ptr_c;
  *ptr_c = *ptr_d;
  *ptr_d = tmp;
  cout << "In function:\n" << *ptr_c << " " << *ptr_d << '\n';
}


void main()
{
  int a,b;
  a=5; b=10;
  cout << "Before:\n" << a << " " << b << '\n';

  swapping(&a,&b);
  cout << "After :\n" << a << " " << b << '\n';

  return 0;
}
