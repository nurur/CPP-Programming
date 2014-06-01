// Example: Function argument is Ponter to an Integer 


#include <iostream>
using namespace std;


//function prototype
void func(int* pInt);


int main()
{
  int  n = 44;
  int* p = &n;
  func(p);

  cout << *p << endl;

  return 0;
}




void func(int* pInt)
{
  cout << "The passed value is: " << *pInt << endl;
  cout << "The passed refer is: " <<  pInt << endl;

  //Modify the variable pInt points to
  *pInt = 3;
  cout << "The passed value is: " << *pInt << endl;
  cout << "The passed refer is: " <<  pInt << endl;
}
