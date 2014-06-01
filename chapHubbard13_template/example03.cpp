// Example: 13.4, 13.5, 13.6
// Class Template: Container Class (Vector) 
// Template & Inheritance 


#include <iostream>
using namespace std;


template <class T>
class Vector
{
public:

  Vector(){};
  Vector(const Vector<T>& copy) : size(copy.size), data(new T[size]) { }
  Vector(unsigned n)            : size(n), data(new T[size]) { }
 ~Vector() { delete[] data; }

  Vector<T>& operator=(const Vector<T>&); 
  T& operator[](unsigned i) const { return data[i]; }
  
  unsigned printSize() { return size; }
  
protected:
  unsigned size;
  T* data;
  void copy(const Vector<T>&);
};



// '=' operator overloading
template <class T>
Vector<T>& Vector<T> :: operator=(const Vector<T>& v) 
  { size = v.size;
    data = new T[size];
    copy(v);
    return *this;
  }
  

// 'copy' member function 
template <class T>
void Vector<T> :: copy(const Vector<T>& v) 
{ unsigned minsize = (size < v.size ? size : v.size);
  for (int i = 0; i < minsize; i++)
    data[i] = v.data[i];
}


template <class T>
class Array : public Vector<T>
{
public: 
  Array(){};
  Array(const Array& v) : indx(v.i), Vector<T>(v) { }
  Array(int i, int j)   :   indx(i), Vector<T>(j-i+1) { }
  // how do you write a proper destructor here?

  T& operator[] (int i) const { return Vector<T> :: operator[] (i-indx); }
  int  firstSubscript() const { return   indx; }
  int secondSubscript() const { return indx-1; }

protected:
  int indx;
};


template <class T>
class Matrix  
{
public:
  Matrix(){};
  Matrix(const Matrix&);
  Matrix(unsigned r=1, unsigned c=1) : row(r) 
  { for (int i=0; i<r; i++) row[i] = new Vector<T>(c); }
 ~Matrix()
  { for (int i=0; i<row.printSize(); i++) delete[] row[i]; }

  unsigned rows() { return     row.printSize(); }
  unsigned cols() { return row[0]->printSize(); }

protected:
  Vector< Vector<T>* > row;
};




int main()
{
  Vector<short> u(8);
  u[5] = 127;
  Vector<short> v = u;
  Vector<short> w(3);

  cout << endl;
  cout << "size of the Vector u: " << u.printSize(); cout << endl;
  cout << "size of the Vector u: " << v.printSize(); cout << endl;
  cout << "size of the Vector w: " << w.printSize(); cout << endl;
  cout << endl;

  Array<int> x(1,3);
  x[1] = 1;   x[2] = 2;   x[3] = 3;

  cout << "size of the Vector x: " <<  x.printSize(); cout << endl;
  cout << "x.firstSubscript()  : " <<   x.firstSubscript() << endl;
  cout << "x.secondSubscript() : " <<  x.secondSubscript() << endl;


  Matrix<float> a(2,3);
  //a[0][0] = 0.0; a[0][1] = 1.0; a[0][2] = 2.0;
  //a[1][0] = 2.0; a[1][1] = 1.0; a[1][2] = 0.0;


  cout << endl;
  return 0;
}
