// EXAMPLE 10.10: Implementing Destructor function for Ratio Class 
//                Implementing Copy Constructor function for Ratio Class 
//                Tracing calls to the Copy Constructor function


#include <iostream>
using namespace std;


class Ratio
{
public :
  Ratio(int n=0, int d=1) : num(n), den(d) 
  { cout << " Object is born\n"; }

  ~Ratio() { cout << " Object is dead\n"; }

  Ratio(const Ratio& r)   : num(r.num), den(r.den) 
  { cout << " Copy Constructor is called\n"; }

  int numerator();    // access function to the private data 
  int denominator();  // access function to the private data 

  float convert();
  void invert();
  void print();
  
private:
  int num, den;
};


int main ()
{
  Ratio x, y(4), z(22,7);
  cout << endl;

  cout << " Ratio x : "; x.print(); cout << endl;
  cout << " Ratio y : "; y.print(); cout << endl;
  cout << " Ratio z : "; z.print(); cout << endl;
  cout << endl;

  cout << " z  = " << z.convert();  cout << endl;

  z.invert();
  cout << " 1/z = "; z.print();     cout << endl;
  cout << endl;

  // use of 'copy constructor' 
  Ratio yy(z);
  cout << " Ratio yy : "; yy.print(); cout << endl;
  cout << " " << yy.numerator() << ", " << yy.denominator()<< endl;


  //const Ratio PI(22,7);
  //PI.print();

  cout << endl;
  return 0;
}  



float Ratio :: convert()
{return float(num)/den;}

void Ratio :: invert()
{int tmp = num; num = den; den = tmp;}

void Ratio :: print() 
{cout << num << '/' << den;}

int Ratio :: numerator()
{return num;}

int Ratio :: denominator()
{return den;}
