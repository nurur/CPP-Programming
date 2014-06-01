// Example: 12.6
// Inheritance  
// Dominating a Data Member 
// Overriding a Member Function 


#include <iostream>
using namespace std;



class X
{
  public:
  X() { };
 ~X() { cout << "~X::X() Destructor Executing \n"; }

  void f() { cout << "X::f() Executing \n"; }
  int a;
};

class Y : public X
{
  public:
  Y() { };
 ~Y() { cout << "~Y::Y() Destructor Executing \n"; }

  void f() { cout << "Y::f() Executing \n"; }
  int a;
};




int main()
{
  X x;
  x.a = 22;
  x.f();
  cout << "x.a   = " << x.a   << endl;
  cout << endl;
  
  Y y;
  y.a    = 44;     // Assign 44 to a defined in Y 
  y.X::a = 66;     // Assign 66 to a defined in X 
  y.f();           // Invokes y defined in Y
  y.X::f();        // Invokes y defined in X
  cout << "y.a    = " << y.a << endl;
  cout << "y.X::a = " << y.X::a << endl;
  cout << endl;
 
  X xx = y;
  cout << "xx.a = " << xx.a << endl;


  return 0;
}
