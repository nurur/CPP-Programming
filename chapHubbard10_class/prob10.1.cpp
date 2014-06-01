// Problem 10.1 
// Point Class 


#include <cmath>
#include <iostream>
using namespace std;


class Point
{
public :
  Point(double x=0.0, double y=0.0, double z=0): _x(x), _y(y), _z(z){}; 
                                                    // default constructor
  Point(const Point& P);                            // copy constructor

  double norm();
  void negate();
  void print();

private:
  double _x, _y, _z;
};



int main()
{
  Point p1, p2(1,1,1);
  cout<< endl;

  p1.print(); cout << endl;
  p2.print(); cout << endl;

  p2.norm(); cout << endl;

  cout << endl;
  return 0;
}




double Point :: norm() 
{ cout << "the norm is: " << sqrt(_x*_x + _y*_y + _z*_z);
  return sqrt(_x*_x + _y*_y + _z*_z);}

void Point :: negate() 
{ _x = -1.* _x; 
  _y = -1.* _y; 
  _z = -1.* _z; 
}

void Point :: print()
{cout << "x= " << _x << ", y= " << _y << ", z= " << _z;}

