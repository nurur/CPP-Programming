// Example: Polymorphic Class in C++, part 1
// Base class and Derived classes
// "virtual" function & pointer to base class


#include <iostream>
using namespace std;

class CPolygon 
{
public:
  //CPolygon();                           // default
  //CPolygon(const CPolygon&);            // copy
  //virtual ~CPolygon();                  // virtual destructor 

  virtual int area() { return 0; }      // virtual function 
  void set_values (int a, int b) { width=a; height=b; }

protected:
  int width, height;
};


class CRectangle: public CPolygon 
{public:
  //CRectangle();
  //CRectangle(const CRectangle&);
  //~CRectangle();

  int area () { return (width * height); }
};


class CTriangle: public CPolygon 
{public:
  //CTriangle();
  //CTriangle(const CTriangle&);
  //~CTriangle();

  int area () { return (width * height/2); }
};




int main() 
{
  CRectangle rect;
  CTriangle  trgl;

  CPolygon* ppoly1 = &rect;
  CPolygon* ppoly2 = &trgl;
  cout << endl;

  ppoly1->set_values(4,5);
  ppoly2->set_values(4,5);

  cout << ppoly1->area() << endl;
  cout << ppoly2->area() << endl;

  // if NOT use 'virtual' function
  //cout << rect.area() << endl;
  //cout << trgl.area() << endl;

  cout << endl;
  return 0;
}

