// Ratio Class
// Interface and Implementation File


#include <iostream>
using namespace std;


#ifndef RATIO_HPP
#define RATIO_HPP


class Ratio
{
friend Ratio operator*(const Ratio&, const Ratio&); // arithmatic operator
friend bool operator==(const Ratio&, const Ratio&); // relational operator
friend istream& operator>>(istream&, Ratio&);       // input stream operator
friend ostream& operator<<(ostream&, const Ratio&); // output stream operator

public :
  Ratio(){};                                        // default constructor 
  Ratio(const Ratio& r)   : num(r.num), den(r.den)  // copy constructor 
  { cout << " Copy Constructor is called\n"; }
  Ratio(int n=0, int d=1) : num(n), den(d) { }      // constructor

  Ratio& operator=(const Ratio&);                   // copy assignment operator
  void print();

private:
  int num, den;
};



// Definiton of friend function for arithmatic operator
Ratio operator*(const Ratio& x, const Ratio& y)
{ Ratio z (x.num * y.num,  x.den * y.den);
  return z;
}

// relational operator
bool operator==(const Ratio& x, const Ratio& y)
{ return (x.num * y.num == x.den * y.den);
}

// input stream operator
istream& operator>>(istream& istr, const Ratio& r)
{ cout << "\t  Numerator : "; istr >> r.num;
  cout << "\tDenominator : "; istr >> r.den;
  return istr;
}

// output stream operator
ostream& operator<<(ostream& ostr, const Ratio& r)
{ return ostr << r.num << '/' << r.den;
}



// Definition of member function for copy assignment operator
Ratio& Ratio :: operator=(const Ratio& r)
{ num = r.num;
  den = r.den;
  return *this;
}

// Definition of member function for print ratio
void Ratio :: print()
{cout << num << '/' << den;}


#endif  // ratio.hpp
