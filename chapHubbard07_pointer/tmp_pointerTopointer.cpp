// Example: Function argument is Pointer to Pointer 

/*
 * ppInt is the ptr-to-ptr. We will never modify this because if we do, 
 * we'll lose our grip on the address of the pointer it is pointing to.
 
 * ppInt is the pointed pointer. If we modify this, we are modifying the 
 * contents of the pointed pointer, which is an address and in the above 
 * example, 'p'. In other words, we are effectively modifying what 'p' 
 * points to.

 * ppInt is the dereferenced twice variable which is what pvar points to.
*/

#include <iostream>
using namespace std;


//function prototype
void func(int** ppInt);


int main()
{
  int  n = 44;
  int* p = &n;
  func(&p);

  return 0;
}




void func(int** ppInt)
{
  /*
  //Modify the pointer, ppInt points to
  *ppInt = &g_One;
  
  //You can also allocate memory, depending on your requirements
  *ppInt = new int;
  
  //Modify the variable, *ppInt points to
  **ppInt = 3;
  */

  cout << "The passed value is: " << **ppInt << endl;
  cout << "The passed refer is: " <<  ppInt << endl;

}
