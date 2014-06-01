// problem 7.4, chap 7 (C++, J R Hubbard)
// write a function that returns numerical integration of a 
// given function f at a given range 
 

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



float funcInt(float lower, float upper, float (*func)(float x))
{

  int n   = 10;
  float h = (upper-lower)/n;
 
  float integration = 0;  
  for (int i=1; i<=n; i++) 
    integration += ( (*func)(lower + i*h) * h );
      
  return integration;
}


int main()
{
  const int SIZE = 15;
  float a[SIZE] = {0.2, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0, 7.5, 
		   10., 20., 50.25, 100, 200.12};
  float b[SIZE] = {0.3, 0.6, 1.5, 2.0, 3.0, 3.5, 5.0, 6.0, 10.,11.5, 
		   12., 30., 70.25, 110.0, 205.12};
  
  for (int i=0; i<SIZE; i++)
    {
      float lower = a[i];
      float upper = b[i];
      float y1 = funcInt(lower,upper,funcLinear);
      cout << "The derivative of the linear function is: " << y1 << endl;

      float y2 = funcInt(lower,upper,funcSquare);
      cout << "The derivative of the square function is: " << y2 << endl;

      float y3 = funcInt(lower,upper,funcCube);
      cout << "The derivative of the square function is: " << y3 << endl;
      cout << endl;
    }


  return 0;
}
