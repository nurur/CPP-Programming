// EXAMPLE 10.3: 
// Implementing multiple Constructor functions for Ratio Class 


#include <iostream>
using namespace std;


/* method 1 */
class Ratio
{
public :
  Ratio(int n=0, int d=1) : num(n), den(d) { }

  float convert();
  void invert();
  void print();
  
private:
  int num, den;
};


int main ()
{
  Ratio x, y(4), z(22,7);

  cout << " Ratio x : "; x.print(); cout << endl;
  cout << " Ratio y : "; y.print(); cout << endl;
  cout << " Ratio z : "; z.print(); cout << endl;
  cout << endl;

  cout << " z  = " << z.convert() << endl;
  
  z.invert();
  cout << " 1/z = "; z.print();

  cout << endl;
  return 0;
}  



//Ratio :: Ratio(int n=0, int d=1) : num(n), den(d) { }

float Ratio::convert()
{return float(num)/den;}

void Ratio::invert()
{int tmp = num; num = den; den = tmp;}

void Ratio::print()
{cout << num << '/' << den;}





/* method 2
class Ratio
{
public :
  Ratio();
  Ratio(int);
  Ratio(int, int); 

  float convert();
  void invert();
  void print();
  
private:
  int num, den;
};


int main ()
{
  Ratio x, y(4), z(22,7);

  cout << " Ratio x : "; x.print();
  cout << " Ratio y : "; y.print();
  cout << " Ratio z : "; z.print();
  cout << endl;

  cout << " z  = " << z.convert() << endl;
  
  z.invert();
  cout << " 1/z = "; z.print();

  cout << endl;
  return 0;
}  


Ratio :: Ratio()             : num(0), den(1) { }
Ratio :: Ratio(int n)        : num(n), den(1) { }
Ratio :: Ratio(int n, int d) : num(n), den(d) { }

float Ratio::convert()
{return float(num)/den;}

void Ratio::invert()
{int tmp = num; num = den; den = tmp;}

void Ratio::print()
{cout << num << '/' << den;}
*/
