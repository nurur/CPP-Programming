//
// sizeof(Class) function 
// Note:
/*
  from www.msdn.com 
  
  When the sizeof operator is applied to an object of type char, it yields 1. 
  When the sizeof operator is applied to an array, it yields the total number 
  of bytes in that array, not the size of the pointer represented by the array 
  identifier

  When the sizeof operator is applied to a class, struct, or union type, the 
  result is the number of bytes in an object of that type, plus any padding 
  added to align members on word boundaries. 
  
  The sizeof operator never yields 0, even for an empty class.
  
  When the sizeof operator is applied to a reference, the result is the same 
  as if sizeof had been applied to the object itself ?!
  
  The sizeof operator cannot be used with the following operands:
  
  Functions. (However, sizeof can be applied to pointers to functions.)
  Bit fields.
  Undefined classes.
  The type void.
  Dynamically allocated arrays.
  External arrays.
  Incomplete types.
  Parenthesized names of incomplete types.
*/

#include <iostream>
using namespace std;


class checkSizeofClass
{
  char  c; 
  char* d;
  int* p, q;
  int aa, bb, cc;
};


int main()
{
  checkSizeofClass xx;
  cout << "sizeof(xx) : " << sizeof(xx) << endl;

  return 0;
}


