// problem 7.5, chap 7 (C++, J R Hubbard)
// write a function that returns numerical derivative of a 
// given function f at a given point x using the tolerance h
 

#include <iostream>
using namespace std;


float funcLinear(float x)
{
  return (1.*x + 1.);
}

float funcSquare(float x)
{
  return (1.*x*x + 1.);
}

float funcCube(float x)
{
  return (1.*x*x*x + 1.);
}



float funcDvt(float x, float tol, float (*func)(float x))
{
  float derivative = (*func)(x+tol) - (*func)(x-tol);
  derivative       = derivative/2./tol;

  return derivative;
}


int main()
{
  const int SIZE = 15;
  float a[SIZE] = {0.2, 0.5, 1., 1.5, 2., 2.5, 3., 4., 5., 7.5, 
		 10., 20., 50.25, 100, 200.12};
  for (int i=0; i<SIZE; i++)
    {
      float x = a[i];
      float h = 0.01;
      float y1 = funcDvt(x,h,funcLinear);
      cout << "The derivative of the linear function is: " << y1 << endl;

      float y2 = funcDvt(x,h,funcSquare);
      cout << "The derivative of the square function is: " << y2 << endl;

      float y3 = funcDvt(x,h,funcCube);
      cout << "The derivative of the square function is: " << y3 << endl;
      cout << endl;
    }


  return 0;
}
