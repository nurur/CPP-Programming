// Problem 11.5 
// Point Class 


#include <cmath>
#include <iostream>
using namespace std;

class Point
{
friend istream& operator>>(istream&, const Point&); // extraction operator
friend ostream& operator<<(ostream&, Point&);       // insertion operator
friend bool operator==(const Point&,const Point&);  // relational operator
  
public :
  Point(double x=0.0, double y=0.0): _x(x), _y(y) {}; // default constructor
  Point(const Point& P);                              // copy constructor

  //Point& operator=(const Point&);                   // assignment operator
  double norm();
  void negate();
  void print();

private:
  double _x, _y;
};



int main()
{
  Point p1, p2(1,1);
  p1.print(); cout << endl;
  p2.print(); cout << endl;

  p2.norm(); cout << endl;

  cout << endl;
  return 0;
}




double Point :: norm() 
{ cout << "the norm is: " << sqrt(_x*_x + _y*_y);
  return sqrt(_x*_x + _y*_y);}

void Point :: negate() 
{ _x = -1.* _x; 
  _y = -1.* _y; 
}

void Point :: print()
{cout << "x= " << _x << ", y= " << _y ;}


