// Problem 7.23, chap 7 (C++, J R Hubbard)
// Pointer to Function 


#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;


double Func(double x)
{ return (x*x - 2.); }


double root( double (*pf)(double x), double a, double b, int n)
{
  int i;
  double fA, fB;
  
  for(i=0; i<=n; i++)
    {    
      fA = (*pf)(a);
      fB = (*pf)(b);
      //cout << a << " " << b << endl;
      
      //Check the range (function value)
      if (abs(fA) <= 1.E-08) 
	return a;
      
      if (abs(fB) <= 1.E-08) 
	return b;
      
      
      //Adjust the domain 
      if (fA < 0 and fB > 0)
	b = (a+b)/2.;
      
      if (fA < 0 and fB < 0)
	{
	  b = 2.*b-a; 
	  a = (a+b)/2.;
	}	
	
    }
}

  


int main()
{
  double r;
  
  r = root(Func,1,2,50);
  cout << "Calling root function  : " << setprecision(16) << r << endl;
  
  return 0;
}
  
