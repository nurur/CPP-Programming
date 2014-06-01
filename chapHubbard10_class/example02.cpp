// EXAMPLE 10.3: Implementing Constructor function for Ratio Class 


#include <iostream>
using namespace std;


class Ratio
{
public :
  Ratio(int, int);                 // default construtor  
 
  int   numerator() {return num;}  // access function to the private data 
  int denominator() {return den;}  // access function to the private data 

  float convert();
  void invert();
  void print();
  
private:
  int num, den;
};




int main ()
{
  Ratio x(22,7);

  cout << " Implementing Ratio class:" << endl;
  cout << x.numerator() << ", " << x.denominator() << endl;
  cout << endl;

  cout << " Ratio x:" << endl;
  cout << " x  = "; x.print();
  cout << endl;

  cout << " x  = " << x.convert() << endl;
  
  x.invert();
  cout << " 1/x = "; x.print();

  cout << endl;
  return 0;
}  



Ratio :: Ratio(int m, int n)
{num = m; den = n;}

float Ratio :: convert()
{return float(num)/den;}

void Ratio :: invert()
{int tmp = num; num = den; den = tmp;}

void Ratio :: print()
{cout << num << '/' << den;}
