// EXAMPLE: 5.18
// Pass by value and Pass by reference 


#include <iostream>
using namespace std;


void computeCircle(double r, double& a, double& c)
{
  const double PI = 3.14159265358979;
  a = PI*r*r;
  c = 2*PI*r;
}



int main ()
{
  double a,c,r;
  a=0.; c=0.;
  cout << "enter a radius : "; cin >> r;

  computeCircle(r,a,c);
  cout << "area = " << a << ", circumference = " << c << endl;

  return 0;
}


