// Example : 10.4
// Pointer as call-by-value parameter of a function   
// Subtle issue! 


#include <iostream>
using namespace std;


typedef int* intPtr;

void sneaky(intPtr tmp) 
{
  *tmp = 99;
  cout << "Inside function sneaky, *p = " << *tmp << endl;
}


int main()
{
  intPtr p;

  p  = new int;
  *p = 77;
  cout << "Before function call,   *p = " << *p << endl;

  sneaky(p);
  cout << "After function call,    *p = " << *p << endl;

  delete p;

  return 0;
}
