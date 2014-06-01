// EXAMPLE:
// Swap Function 
// With tmp variable
// With XOR algorithm 
// With Pointer variable 


#include <iostream>
using namespace std;



void swap1(int &x, int &y)
{
  int tmp;
  tmp= x;
  x  = y;
  y  = tmp;
}


void swap2(int *x, int *y)
{
  int tmp;    //int *tmp;
  tmp = *x;   // tmp = x;
  *x  = *y;   // *x = *y;
  *y  = tmp;  // *y = *tmp;
}


void swap3(int& x, int& y)
{
  y = x^y;
  x = x^y;
  y = x^y;
}



int main()
{
  int a=22, b=44;
  swap1(a,b);
  cout << "a = " << a << " b = " << b << endl;
   
  int c=22, d=44;
  swap2(&c,&d);
  cout << "c = " << c << " d = " << d << endl;
   
  int e=22, f=44;
  swap3(e,f);
  cout << "e = " << e << " f = " << f << endl;
   
  return 0;
}
