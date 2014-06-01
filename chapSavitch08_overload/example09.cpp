// Example: 8.6
// Class IntPair
// Overloading Function Call operator () 
// Note: 
/*
Unlike all other overloaded operators, you can provide default 
arguments and ellipses in the argument list for the function 
call operator.

class A 
{
void operator()(int a, char b, char c, int d) { }
void operator()(char c, int d = 20) { }
};

int main() {
A a;
a(5, 'z', 'a', 0);
a('z');
// a(); // Error: Does not match any function call in class A
}
*/


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

class Point 
{
public:
  Point() : x(0), y(0) { }

  Point& operator()(int dx, int dy);

  void output() { cout << x << " " << y << endl; } 

private:
  int x, y;
};


Point& Point :: operator()(int dx, int dy) 
{
  this->x += dx;
  this->y += dy;

  return *this;
}



int main() 
{
  Point pt; 
  // Offset coordinate x with 3 points and coordinate y with 2 points.
  pt(3, 2);
  pt.output();

  return 0;
}
