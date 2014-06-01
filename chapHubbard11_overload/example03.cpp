// EXAMPLE 11.4,11.5, 11.6, 11.7, 11.8     
// Alternative form of coding: Creating Header
//
// Overloading Operators : Assignment operator, Arithmatic Operator
//                         Relational Operator


#include "Ratio.hpp"
#include <iostream>
using namespace std;


int main ()
{
  Ratio x, y(4), z(22,7);

  // assignment overloading 
  cout << " assignment overloading,            : " << endl;
  x = y = z; 
  cout << " Ratio x : "; x.print(); cout << endl;
  cout << " Ratio y : "; y.print(); cout << endl;
  cout << " Ratio z : "; z.print(); cout << endl;
  cout << endl;

  //arithmatic overloading 
  cout << " arithmatic overloading, x = y*z   : " << endl;
  x = y*z;
  cout << " Ratio x : "; x.print(); cout << endl;
  cout << endl;

  //relational overloading 
  cout << " relational overloading, x*y==y*z  : " << endl;
  if (y == z)
    {cout << " y and z are equal    "; cout << endl;}
  else 
    {cout << " y and z are not equal"; cout << endl;}

  cout << endl;
  
  // output stream overloading 
  cout << "x : " << x << ", y : " << y << ", z : "<< z << endl;
  cout << endl;



  cout << endl;
  return 0;
}  

