// EXAMPLE 11.4, 11.5
// Overloading Operators : Copy Assignment operator, Arithmatic Operator


#include <iostream>
using namespace std;


class Ratio
{
friend Ratio operator*(const Ratio&, const Ratio&);
  
public :
  Ratio(int n=0, int d=1) : num(n), den(d) { }      // default constructor
  Ratio(const Ratio& r)   : num(r.num), den(r.den)  // copy constructor 
  { cout << " Copy Constructor is called\n"; }
  
  Ratio& operator=(const Ratio&);                   // assignment operator
  void print();

private:
  int num, den;
};



// Friend function  
Ratio operator*(const Ratio& x, const Ratio& y)
{ Ratio z (x.num * y.num,  x.den * y.den);
  return z;
}

// Member function 
Ratio& Ratio :: operator=(const Ratio& r)
{ num = r.num;
  den = r.den;
  return *this;
}

void Ratio :: print()
{cout << num << '/' << den;}




int main ()
{
  Ratio x, y(4), z(22,7);

  // assignment overloading 
  cout << " assignment overloading,         : " << endl;
  x = y = z; 
  cout << " Ratio x : "; x.print(); cout << endl;
  cout << " Ratio y : "; y.print(); cout << endl;
  cout << " Ratio z : "; z.print(); cout << endl;
  cout << endl;

  //arithmatic overloading 
  cout << " arithmatic overloading, x = y*z : " << endl;
  x = y*z;
  cout << " Ratio x : "; x.print(); cout << endl;

  cout << endl;
  return 0;
}  

