// Example:
// Overloading dereference operator * 


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;




class X 
{
public:
  X() : m_var(0) { }

  int operator*() const { return 5; }
  void output() { cout << m_var << endl;}
  
private:
  int m_var;
};



class Y
{
public:
  Y() : m_var(0) { }

  Y& operator*();
  void output() { cout << m_var << endl;}
  
private:
  int m_var;
};

Y& Y :: operator*() 
  {
    this->m_var = 10;
    return *this; 
  }




int main()
{
  X x;
  int i = *x;  // i = ( x.operator*() )
  cout << "Assigned value: " << i << endl;
  cout << endl;


  Y y1;
  Y y2 = *y1;
  cout << "Assigned value: ";
  y2.output();
 
  return 0;
}
