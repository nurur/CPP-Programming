// Problem 8.6
// Class MyInteger


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


class MyInteger
{
public:
  MyInteger();
  MyInteger(int number);
  
  int& operator[](int index);


private:
  int num;
  int  lastDigit ; 
  int middleDigit; 
  int  firstDigit; 

};

MyInteger :: MyInteger() : num(0) { }
MyInteger :: MyInteger(int number) : num(number) { }


int& MyInteger :: operator[](int index)
{
  lastDigit   = num % 10;
  middleDigit = (num / 10) % 10;
  firstDigit  = num / 100;

  if (index == 1) 
    { 
      return lastDigit;
    }
  else if (index == 2)
    { 
      return middleDigit;
    }  
  else if (index == 3)
    {
      return firstDigit;
    }
  else
    {
      cout << "Illigal index value;\n";
      exit(1);
    }
}



int main()
{
  MyInteger x(418);
  cout << "x[3] = " << x[3] << ", " 
       << "x[2] = " << x[2] << ", " 
       << "x[1] = " << x[1] << endl;

  return 0;
}
