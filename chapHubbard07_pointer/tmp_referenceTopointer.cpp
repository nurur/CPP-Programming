// Example: Function argument is Reference to Pointer 

/*    
 * rpInt is the reference for the pointer, pvar in the above example.
 
 * rpInt dereferences what 'p' point to, so you get the variable the 
 * pointer, 'p' is pointing to.
 */


#include <iostream>
using namespace std;


//function prototype
void func(int*& rpInt);


int main()
{
  int  n = 44;
  int* p = &n;
  func(p);

  cout << *p << endl;

  return 0;
}




void func(int*& rpInt)
{
  /*
  //Modify what rpInt and pvar is pointing to, to g_One
  rpInt = &g_One;
  
  //You can also allocate memory, depending on your requirements
  rpInt = new int;
  
  //Modify the variable rpInt points to
  *rpInt = 3;
  */


  cout << "The passed value is: " << *rpInt << endl;
  cout << "The passed refer is: " <<  rpInt << endl;

  //Modify the variable rpInt points to
  *rpInt = 33;
  cout << "The passed value is: " << *rpInt << endl;
  cout << "The passed refer is: " <<  rpInt << endl;
}
