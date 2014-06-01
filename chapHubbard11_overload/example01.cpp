// EXAMPLE 11.1,11.2,11.3
// Overloading Operators : Assignment operator


#include <iostream>
using namespace std;


class Ratio
{
public :
  Ratio(int n=0, int d=1) : num(n), den(d) { }      //default constructor
  Ratio(const Ratio& r)   : num(r.num), den(r.den)  //copy constructor 
  { cout << " Copy Constructor is called\n"; }
  
  Ratio& operator=(const Ratio&);                    //copy assignment operator
  void print();

private:
  int num, den;
};




int main ()
{
  Ratio x, y(4), z(22,7);
  x = y = z; 
  cout << endl;

  cout << " Ratio x : "; x.print(); cout << endl;
  cout << " Ratio y : "; y.print(); cout << endl;
  cout << " Ratio z : "; z.print(); cout << endl;

  cout << endl;
  return 0;
}  



Ratio& Ratio :: operator=(const Ratio& r)
{ this->num = r.num;  //or, num = r.num;
  this->den = r.den;  //or, den = r.den;
  return *this;
}

void Ratio :: print()
{cout << num << '/' << den;}
