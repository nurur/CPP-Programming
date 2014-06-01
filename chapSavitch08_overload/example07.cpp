// Example: 8.6
// Class IntPair
// Overloading Increment operators as friend functions of the class


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


class IntPair
{
  friend ostream& operator<<(ostream& out, const IntPair& ip);
  
public:
  IntPair();
  IntPair(int firstValue, int secondValue);

  IntPair operator++();      // Prefix version 
  IntPair operator++(int);   // postfix version 

  void  setFirst(int newValue);
  void setSecond(int newValue);

  int  getFirst() const;
  int getSecond() const;

private:
  int first;
  int second;
};



IntPair :: IntPair()
{
  first  = 0; 
  second = 0;
}

IntPair :: IntPair(int firstValue, int secondValue)
{
  first  =  firstValue; 
  second = secondValue;
}

// Prefix version 
/*
IntPair IntPair :: operator++()
{
  first++;
  second++;
  return IntPair(first, second);
}
*/
IntPair IntPair :: operator++()
{
  first++;
  second++;
  return *this;
}

// Postfix version 
/*
IntPair IntPair :: operator++(int dummy)
{
  int tmp1 = first;
  int tmp2 = second;
  first++;
  second++;
  return IntPair(tmp1, tmp2);
}
*/
IntPair IntPair :: operator++(int dummy)
{
  IntPair tmp = *this;
  first++;
  second++;
  return tmp;
}



void IntPair :: setFirst(int newValue)
{
  first = newValue;
}

void IntPair :: setSecond(int newValue)
{
  second = newValue;
}

int IntPair :: getFirst() const
{
  return first;
}

int IntPair :: getSecond() const
{
  return second;
}


ostream& operator<<(ostream& ostr, const IntPair& ip) 
{
  ostr << ip.first << " " << ip.second;
  return ostr;
}






int main()
{

  // Postfix
  IntPair a(1,2);
  cout << "Postfix a++: Start value of object a: ";
  cout << a.getFirst() << " " << a.getSecond() << endl;

  IntPair b = a++;
  cout << "Value returned: ";
  cout << b.getFirst() << " " << b.getSecond() << endl;
  
  cout << "Changed object: ";
  cout << a.getFirst() << " " << a.getSecond() << endl;
  cout << endl;


  //Prefix 
  a = IntPair(1,2);
  cout << "Prefix a++: Start value of object a : ";
  cout << a.getFirst() << " " << a.getSecond() << endl;

  IntPair c = ++a;
  cout << "Value returned: ";
  cout << c.getFirst() << " " << c.getSecond() << endl;
  
  cout << "Changed object: ";
  cout << a.getFirst() << " " << a.getSecond() << endl;
  cout << endl;


  // check 
  cout << "Check: Self-test Exercise 12." << endl;
  IntPair d(1,2);
  cout << d << endl;
  cout << "---" << endl;

  IntPair e = (d++)++;
  cout << e << endl;
  cout << d << endl;
  cout << "---" << endl;

  return 0;
}
