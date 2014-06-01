// Example
// Inheritance 
// Pointers and References to the Base and Derived Class 
// Base* pbase = &Derived;
// Base& rbase = Derived
//
// Source: http://www.learncpp.com/cpp-tutorial/
// 121-pointers-and-references-to-the-base-class-of-derived-objects/
//
// Note :
/* 
 * When a Derived object is created, it contains a Base part (which is 
 * constructed first), and a Derived part (which is constructed second). 
 * Remember that inheritance implies an is-a relationship between two 
 * classes. Since a Derived is-a Base, it is appropriate that Derived 
 * contain a Base part of it.
*/


#include <iostream>
using namespace std;


class Base
{
protected:
  int m_nValue;
  
public:
  Base(int nValue) : m_nValue(nValue) { }
  
  const char* GetName() { return "Base"; }
  int GetValue() { return m_nValue; }
};


class Derived: public Base
{
public:
  Derived(int nValue) : Base(nValue) { }
  
  const char* GetName() { return "Derived"; }
  int GetValueDoubled() { return m_nValue * 2; }
};



int main()
{
    Derived cDerived(5);
    cout << "cDerived is a " << cDerived.GetName() 
	 << " and has value " << cDerived.GetValue() 
	 << endl;
    cout << endl;   

    Derived &rDerived = cDerived;
    Derived *pDerived = &cDerived;
    cout << "rDerived is a " << rDerived.GetName() 
	 << " and has value " << rDerived.GetValue() 
	 << endl;    
    cout << "pDerived is a " << pDerived->GetName() 
	 << " and has value " << pDerived->GetValue() 
	 << endl;
    cout << endl;

    Base &rBase = cDerived;
    Base *pBase = &cDerived;
    cout << "rBase is a " << rBase.GetName() 
	 << " and has value " << rBase.GetValue() 
	 << endl;
    cout << "pBase is a " << pBase->GetName() 
	 << " and has value " << pBase->GetValue() 
	 << endl;
 
    return 0;
}
