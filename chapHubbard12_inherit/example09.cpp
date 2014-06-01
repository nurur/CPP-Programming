// Example:
// Public, Protected and Private data members 


#include <iostream>
using namespace std;


class X
{
public    : int a;
protected : int b;
private   : int c;
};

class Y : public X
{
public    : int d; 
}; 


int main()
{
  X x;
  Y y;

  x.a = 10;
  y.d = 40;

  cout << x.a << endl;
  cout << y.d << endl;
  return 0;
}
