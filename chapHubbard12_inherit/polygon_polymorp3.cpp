// Example: Polymorphic Class in C++, part 3
// Base class and Derived classes 
// "Pure Virtual Function" & Pointer to Base Class
// Dynamic memory allocation 



#include <iostream>
using namespace std;


class CPolygon   
// Abstract class
{
protected:
  int width, height;

public:
  void set_values (int a, int b) { width=a; height=b; }
  virtual int area() = 0;         // pure virtual function 

  void printarea(void) 
  { cout << this->area() << endl; }
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
  CPolygon* ppoly1 = new CRectangle;  // dynamic allocation 
  CPolygon* ppoly2 = new CTriangle;   // dynamic allocation 
  cout << endl;

  ppoly1->set_values(4,5);
  ppoly2->set_values(4,5);

  ppoly1->printarea();
  ppoly2->printarea();


  delete ppoly1;                     // remove dynamic allocation 
  delete ppoly2;                     // remove dynamic allocation 

  cout << endl;
  return 0;
}

