// Problem 11.1, 11.3, and 11.4

#include <iostream>
using namespace std;

class Ratio
{
friend istream& operator>>(istream&, Ratio&);       // input stream operator
friend ostream& operator<<(ostream&, const Ratio&); // output stream operator
friend bool operator==(const Ratio&, const Ratio&); // relational operator
friend bool operator<(const Ratio&, const Ratio&);  // relational operator
friend Ratio operator+(const Ratio&, const Ratio&); // arithmatic operator
friend Ratio operator-(const Ratio&, const Ratio&); // arithmatic operator
friend Ratio operator*(const Ratio&, const Ratio&); // arithmatic operat
friend Ratio operator%(const Ratio&, const Ratio&); // arithmatic operator

friend Ratio operator-(const Ratio&);               // negation operator


public :
  Ratio(int n=0, int d=1) : num(n), den(d) { }      // default constructor
  Ratio(const Ratio& r)   : num(r.num), den(r.den)  // copy constructor 
  { cout << " Copy Constructor is called\n"; }
  
  Ratio& operator=(const Ratio&);                   // assignment operator
  void print();

private:
  int num, den;
};



int main()
{
  Ratio x, y;
  cin >> x >> y;
  cout <<"x = " << x << ", y = "<< y << endl;

  return 0;
}







// Definiton of friend function ************************
// input stream operator
istream& operator>>(istream& istr, Ratio& r)
{ //cout<< "\t  Numerator : "; istr >> r.num;
  //cout<< "\tDenominator : "; istr >> r.den;
  //return istr;
  
  return istr >> r.num >> r.den;
}

//output stream operator
ostream& operator<<(ostream& ostr, const Ratio& r)
{ return ostr << r.num << '/' << r.den;
}

// relational operator
// equal-to between two ratios [a/b == c/d -> (a*d == b*c]
bool operator==(const Ratio& x, const Ratio& y)
{ return (x.num * y.num == x.den * y.den);
}
// less-than between two ratios [a/b < c/d = (a*d-b*c)/bd]
bool operator<(const Ratio& x, const Ratio& y)
{ return (x.num*y.den < x.den*y.num);
}


// arithmatic operator
// addition of two ratios [a/b + c/d = (a*d+b*c)/bd]
Ratio operator+(const Ratio& x, const Ratio& y)
{ Ratio z (x.num*y.den + x.den*y.num,  x.den*y.den);
  return z;
}
// subtraction of two ratios [a/b - c/d = (a*d-b*c)/bd]
Ratio operator-(const Ratio& x, const Ratio& y)
{ Ratio z (x.num*y.den - x.den*y.num,  x.den*y.den);
  return z;
}
// multiplication of two ratios [a/b * c/d = a*c/b*d]
Ratio operator*(const Ratio& x, const Ratio& y)
{ Ratio z (x.num*y.num,  x.den*y.den);
  return z;
}
// division of two ratios [a/b % c/d = a*d/b*c]
Ratio operator%(const Ratio& x, const Ratio& y)
{ Ratio z (x.num*y.den,  x.den*y.num);
  return z;
}


// negation operator
// negation of a ratio [a/b = num/den]
Ratio operator-(const Ratio& r)
{ Ratio z (-r.num, r.den);
  return z;
}


// Definition of member function ************************
// assignment operator
Ratio& Ratio::operator=(const Ratio& r)
{ num = r.num;
  den = r.den;
  return *this;
}

// Definition of member function for print ratio
void Ratio::print()
{cout << num << '/' << den;}



