// Review Question 12.13, chap 12 (C ++, J Hubbard)
// Protected Data Member


#include <iostream>
using namespace std;


//-----------------------
class X
{
public:
  void f(X x, int c);

protected:
  int a;
};

void X :: f(X x, int c)    // Legal invocation of protected data member 
{ x.a = c; }


// ---------------------
class Y : public X 
{
public:
  void f(X x, int c);
};

void Y :: f(X x, int c)    // Illegal invocation of protected data member 
{ x.a = c; }

// void Y :: f(Y y, int c) // Legal invocation of protected data member 
// { y.a = c; }




int main()
{

  return 0;
} 
