// Problem 12.2, chap 12 (C++, C Hubbard)
// Inheritance 


#include <cmath>
#include <iostream>
using namespace std;


const double PI = 3.141592653589;


class Shape
{
public:
  Shape();
  Shape(const Shape&);
 ~Shape();

  virtual float area() = 0;   
  virtual void print() = 0;
};


class TwoDimensional: public Shape
{
public:
  virtual float perimeter() = 0;
};


class ThreeDimensional: public Shape
{
public:
  virtual float volume() = 0;
};



class Circle : public TwoDimensional
{
public:
  Circle();
  Circle(const Circle&);
  Circle(float r) : radius(r) { }

  float perimeter() {      return 2. * PI * radius;           } 
  float      area() {    return PI * radius * radius;         }
  void      print() { cout << "Shape is a 2D circle" << endl; }

private:
  float radius;
};



class Cone : public ThreeDimensional
{
public:
  Cone();
  Cone(const Cone&);
  Cone(float r, float h) : radius(r),height(h) { }

  float    volume() { return PI * radius * radius * height/3; }
  float      area() 
  {float s = sqrt(radius*radius + height*height);
    return PI * radius * (radius + s); 
  }
  void      print() { cout << "Shape is a 3D Cone" <<endl;}

private:
  float radius, height;
};





int main()
{
  return 0;
}
