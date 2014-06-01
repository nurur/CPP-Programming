// EXAMPLE 10.1: Implementing Ratio Class 


#include <iostream>
using namespace std;


class Ratio
{
public :
  void assign(int, int);
  float convert();
  void invert();
  void print();
  
private:
  int num, den;
};




int main ()
{
  Ratio x;
  x.assign(22,7);

  cout << " Implementing Ratio class:" << endl;
  cout << " Ratio x:" << endl;
  cout << " x  = "; x.print();
  cout << endl;

  cout << " x  = " << x.convert() << endl;
  
  x.invert();
  cout << " 1/x = "; x.print();

  cout << endl;
  return 0;
}  



void Ratio :: assign(int m, int n)
{
  num = m; 
  den = n;
}

float Ratio :: convert()
{return float(num)/den;}

void Ratio :: invert()
{ 
  int tmp;
  tmp = num; 
  num = den; 
  den = tmp;
}

void Ratio :: print()
{cout << num << '/' << den;}
