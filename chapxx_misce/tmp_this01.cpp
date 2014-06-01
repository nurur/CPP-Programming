/* This pointer:
 
  1. Every object has a special pointer 'this' which points to the 
  object itself.

  2. 'This' pointer is accessible to all members of the class but 
  not to any static members of the class.

  3. 'This' pointer can be used to find the address of the object 
  in which the function is a member.

  4. Presence of this pointer is not included in the 'sizeof' 
  calculations.
*/



#include <iostream>
using namespace std;


class X {
private:
  int a;

public:
  void Set_a(int a) { this->a = a; }
    // 'this' pointer is used to retrieve 'x.a'
    // hidden by the automatic variable 'a'

  void Get_a() { cout << "a = " << a << endl; }
  void Prt_a() 
  { cout << "address of class X          :  " << this    << endl;
    cout << "member data value of class X:  " << this->a << endl;
  }

};




int main() {
  X x;
  int a = 5;   // member data  

  x.Set_a(a);
  x.Get_a();
  x.Prt_a();


  cout << endl;
  return 0;
}

