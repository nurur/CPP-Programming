// Problem 10.7 
// Matrix Class 


#include <cmath>
#include <iostream>
using namespace std;


class Matrix{

public:
  Matrix(double a=0, double b=0, double c=0, double d=0) 
  : _a(a),_b(b),_c(c),_d(d) { } 

  Matrix(const Matrix&);
  //  Matrix(const Matrix&) 
  //: _a(M._a),_b(M._b),_c(M._c),_d(M._d) { }


  bool   isSingular();
  double det();
  Matrix inverse();
  void   print();

private:
  double _a,_b,_c,_d;
};



int main()
{
  Matrix m(1,1,1,2);
 
  if ( m.isSingular() ) 
    {cout << "warning! singular matrix" << endl;} 
  else 
    {cout << m.det();
    }

  cout << endl;
  return 0;
}



// copy constructor 
Matrix :: Matrix(const Matrix& M) 
  : _a(M._a),
    _b(M._b),
    _c(M._c),
    _d(M._d) { }


bool Matrix :: isSingular()
{
  double d = (_a*_d - _b*_c);
  if (d == 0.0) return true;
  return false;
}

double Matrix :: det()
{ double d = (_a*_d - _b*_c);
  return d;
} 

Matrix Matrix :: inverse()
{
  double k = 1./det();
  Matrix tmp (k*_d,-k*_b,-k*_c,k*_a);
  return tmp;
}

void Matrix :: print()
{cout << _a << _b << _c << _d << endl;}
