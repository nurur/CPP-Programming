// EXAMPLE 5.16
// Swap Function 
// With tmp variable
// With XOR algorithm 
// With Pointer variable 



#include <iostream>
using namespace std;



void swapWTtmp(int& x, int& y)
{
  int tmp = x ;
  x = y;
  y = tmp;
}

void swapWOtmp(int& x, int& y)
{
  y = x^y;  // Change y to a new variable 
  x = x^y;  // Perform XOR with x and new y
            // this will change x to old y
  y = x^y;  // Perform XOR with new x and new y
            // this will change new y back to old y
}


void swapWTptr(int *ptr_c, int *ptr_d)
{
  int tmp;
  
  tmp    = *ptr_c;
  *ptr_c = *ptr_d;
  *ptr_d = tmp;
  cout << "In function:\n" << *ptr_c << " " << *ptr_d << '\n';
}




int main()
{
  int m = 22, n = 44;
  cout << "m = " << m << ", n = " << n << endl;
  cout << "Calling swap() with tmp variable     :\n";
  swapWTtmp(m,n);
  cout << "m = " << m << ", n = " << n << endl;


  cout << "Calling swap() without tmp variable  :\n";
  int p = 22, q = 44;
  swapWOtmp(p,q);
  cout << "m = " << p << ", n = " << q << endl;

  cout << "Calling swap() using pointer variable:\n";
  int a=5, b=10;
  cout << "Before:\n" << a << " " << b << '\n';
  swapWTptr(&a,&b);
  cout << "After :\n" << a << " " << b << '\n';


  return 0;
}
