// EXAMPLE: 12.10 
// Polymorphic Class 
// "Virtual" function & Pointer to base class 


#include <iostream>
using namespace std;


class X
{
public:
  virtual void f() {cout << "  base class function X::f() executing" << endl;}
};

class Y : public X
{
public:
  void f() {cout << "derive calss function Y::f() executing" << endl;}
};

class Z : public X
{
public:
  void f() {cout << "derive calss function Z::f() executing" << endl;}
};



int main()
{
  X x;
  Y y;
  Z z;

  X* p1 = &x;
  X* p2 = &y;
  X* p3 = &z;


  p1->f();
  p2->f();
  p3->f();


  cout << endl;
  return 0;
}
