// Example: Polymorphic Class in C++, part 2
// Base class and Derived classes 
// "virtual" function & pointer to base class


#include <iostream>
using namespace std;

class CPolygon 
{protected:
  int width, height;

public:
  void set_values (int a, int b) { width=a; height=b; }
  virtual int area() =0;         // pure virtual function 

  void printarea(void) 
  {
    cout << this->area() << endl;
  }

};

class CRectangle: public CPolygon 
{public:
  int area () { return (width * height); }
};

class CTriangle: public CPolygon 
{public:
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

  ppoly1->printarea();
  ppoly2->printarea();

  //cout << ppoly1->area() << endl;
  //cout << ppoly2->area() << endl;

  cout << endl;
  return 0;
}

