// Example:  This pointer
// http://www.learncpp.com/cpp-tutorial/87-the-hidden-this-pointer/

#include <string>
#include <cstring>
#include <iostream>
using namespace std;


class Calc1
{
private:
    int m_nValue;
 
public:
    Calc1() { m_nValue = 0; }
 
    void  Add(int nValue) { m_nValue += nValue; }
    void  Sub(int nValue) { m_nValue -= nValue; }
    void Mult(int nValue) { m_nValue *= nValue; }
 
    int GetValue() { return m_nValue; }
};



class Calc2
{
public:
    Calc2() { m_nValue = 0; }
 
    Calc2&  Add(int nValue) { m_nValue += nValue; return *this; }
    Calc2&  Sub(int nValue) { m_nValue -= nValue; return *this; }
    Calc2& Mult(int nValue) { m_nValue *= nValue; return *this; }
    
    int GetValue() { return m_nValue; }
 
private:
    int m_nValue;
};



class Calc3
{
public:
  Calc3() { m_nValue = 0; }
  
  Calc3&   Add(Calc3* const THIS, int nValue); 
  Calc3&   Sub(Calc3* const THIS, int nValue); 
  Calc3&  Mult(Calc3* const THIS, int nValue); 
  
  int GetValue(Calc3* const THIS);

private:
    int m_nValue;
};

Calc3&  Calc3:: Add(Calc3* const THIS, int nValue) { m_nValue += nValue; return *THIS; }
Calc3&  Calc3:: Sub(Calc3* const THIS, int nValue) { m_nValue -= nValue; return *THIS; }
Calc3&  Calc3::Mult(Calc3* const THIS, int nValue) { m_nValue *= nValue; return *THIS; }
  
int Calc3::GetValue(Calc3* const THIS) { return (THIS->m_nValue); }






int main()
{
  Calc1 x;
  x.Add(5);
  x.Sub(3);
  x.Mult(4);
  cout << x.GetValue() << endl;
  

  Calc2 y;
  y.Add(5).Sub(3).Mult(4);
  cout << y.GetValue() << endl;


  Calc3 z;
  z.Add(&z,5).Sub(&z,3).Mult(&z,4);
  cout << z.GetValue(&z) << endl;

 return 0;
} 
