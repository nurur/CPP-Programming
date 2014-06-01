// Example:
// Overloading Conversion Operator
// Note:
// operator int(), operator double() , operator char()


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



class Fraction 
{
public:
  Fraction(int n = 0, int d = 1) 
    : numerator(n), denominator(d) { }
  
  operator float() const
  { return float( numerator ) / float( denominator ); }
  
  friend ostream& operator<<(ostream& outs, const Fraction& frac);
  
private:
  int numerator;
  int denominator;
};


ostream& operator << (ostream& outs, const Fraction& frac)
{
  int n = frac.numerator;
  int d = frac.denominator;

  if (d < 0)
    {
      n = -n;
      d = -d;
    }

  return outs << n << "/" << d;
}



int main()
  {
  Fraction f(2,-5);
  float v = f;

  cout << f << " = " << v << endl;

  return 0;
  }
