// Example: Inheritance in C++
// Base class and Derived classes


#include <iostream>
using namespace std;


class CPolygon 
{
public:
  CPolygon();
  CPolygon(const CPolygon& Pol) : width(Pol.width), height(Pol.height) { }
 ~CPolygon();

  void set_values (int a, int b) { width=a; height=b;}

protected:
  int width, height;
};


class COutput 
{public:
  void output (int i) { cout << i << endl; }
};



class CRectangle: public CPolygon, public COutput 
{public:
  CRectangle();
  CRectangle(const CRectangle&);
 ~CRectangle();

  int area() { return (width * height); }
};

class CTriangle: public CPolygon, public COutput 
{public:
  CTriangle();
  CTriangle(const CTriangle&);
 ~CTriangle();

  int area() { return (width * height/2); }
};



int main() 
{
  CRectangle rect;
  CTriangle trgl;

  rect.set_values (4,5);
  trgl.set_values (4,5);
 
  cout << "area of rectangle : " << rect.area() << endl;
  cout << "area of triangle  : " << trgl.area() << endl;
  cout << endl;

  rect.output( rect.area() );
  rect.output( trgl.area() );
  
  cout << endl;
  return 0;
}
