// EXAMPLE 11.10
// Overloading Subscript [] Operator 


#include <cstdlib>
#include <iostream>
using namespace std;



class Ratio
{
  friend ostream& operator<<(ostream& ostr, const Ratio& r);
  
public :
  Ratio(int n=0, int d=1) : num(n), den(d) { }      // default constructor
  Ratio(const Ratio& r)   : num(r.num), den(r.den)  // copy constructor 
  { cout << " Copy Constructor is called\n"; }
  
  int& operator[](int index);                      // subscript operator
  
private:
  int num, den;
};


// output stream operator
ostream& operator<<(ostream& ostr, const Ratio& r)
{ ostr << r.num << '/' << r.den;
  return ostr;
}

// subscript operator 
int& Ratio :: operator[](int index)
{
  if (index == 1) 
    { 
      return num;
    }
  else if (index == 2)
    { 
      return den;
    }  
  else
    {
      cout << "Illigal index value;\n";
      exit(1);
    }
}



int main()
{
  Ratio x(22,7);
  cout << "x = " << x << endl; 
  cout << "x[1] = " << x[1] << "  " << "x[2] = " << x[2] << endl;
  
  return 0;
}
