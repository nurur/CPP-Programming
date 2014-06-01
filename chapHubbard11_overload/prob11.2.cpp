// Problem 11.2
// Vector Class


#include <iostream>
using namespace std;

class Vector
{
friend ostream& operator<<(ostream&, const Vector&); // insertion operator
friend istream& operator>>(istream&, Vector&);       // extraction operator
friend bool operator==(const Vector&,const Vector&); // relational operator
  
public :
  Vector(int sz=1, double dt=0.0);      // default constructor
  Vector(const Vector&);                // copy constructor 
  
  ~Vector();                                        // destructor operator

  const Vector& operator=(const Vector&);           // assignment operator
  double& operator[](int) const;                    // subscript operator
  void print();

private:
  int size;
  double* data;
};



int main()
{
  //  Vector x,y;
  //cin >> x >> y;
  //cout <<"x = " << x << ", y = "<< y << endl;

  return 0;
}







// Definiton of friend function ************************
//insertion operator
ostream& operator<<(ostream& ostr, const Vector& x)
{ 
  for (int i = 0; i < x.size-1; i++)
    { ostr << x[i] << ", ";
      if ((i+1)%8 == 0) cout << "\n ";
    }
  return ostr; //return ostr << x[j] << ")\n";
}


// extraction operator
istream& operator>>(istream& istr, Vector& x)
{  
  for (int i = 0; i <  x.size; i++)
    { cout << i << ": ";
      istr >> x[i];
    }
  return istr;
}


// relational operator
// equality between two vectors[x == y]
bool operator==(const Vector& x, const Vector& y)
{if (x.size != y.size) return 0; 
  
  for (int i = 0; i <  x.size; i++)
    if (x.data[i ]!=  y.data[i]) return 0;
  
  return 1;
}


// Definition of member function ************************
// assignment operator
const Vector& Vector :: operator=(const Vector& x)
{ if (&x != this)
    {
      delete [] data;
      size = x.size;
      data = new double[x.size];
      for (int i = 0; i <  x.size; i++)
	data[i] = x.data[i];
    }

  return *this;
}

// destructor operator
Vector :: ~Vector() 
{ delete [] data;
  size = 0;
  data = NULL;
}

// subscript constructor
double& Vector :: operator[](int i) const
{return data[i];}


// Definition of member function for print ratio
void Vector :: print()
{cout << size << data;}



