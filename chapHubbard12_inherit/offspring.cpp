// Example: Inheritance 
// Constructors in the Base class and Derived classes
// 
// Note: 
/* 
 * If a constructor definition for a derived class does not include 
 * an version invocation of a constructor for the base class, then 
 * the default of the base class constructor is invoked automatically. 
 */
 

#include <iostream>
using namespace std;


class Mother 
{
public:
  Mother()       { cout << "Mother  : no parameters\n"; }
  Mother(int a)  { cout << "Mother  : int parameter\n"; }
};


class Daughter : public Mother 
// The constructor in Class Daughter does not include 
// the base class constructor 
{
public:
  Daughter(int a)  { cout << "Daughter: int parameter\n\n"; } // 
};

class Son : public Mother 
{
public:
  Son(int a) : Mother(a)     { cout << "Son     : int parameter\n\n"; }
};




int main () 
{
  
  Daughter Cynthia(0);
  Son Daniel(0);
  
  return 0;
}
