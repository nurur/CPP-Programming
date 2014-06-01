// Example: 8.6
// Class IntPair
// Overloading Array (Subscript) operator [] 

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



class charPair
{
public:
  charPair();
  charPair(char firstValue, char secondValue);

  char& operator[](int index); 

private:
  char first;
  char second;
};


charPair :: charPair()
{
  first  = NULL; 
  second = NULL; 
}

charPair::  charPair(char firstValue, char secondValue) 
{ 
  first  = firstValue;
  second = secondValue;
}


char& charPair :: operator[](int index)
{
 if (index == 1) 
    { 
      return first;
    }
  else if (index == 2)
    { 
      return second;
    }  
  else
    {
      cout << "Illigal index value;\n";
      exit(1);
    }
}



int main()
{
  charPair a;
  a[1] = 'A';
  a[2] = 'B';

  cout << "a[1] and a[2] are: " << endl;
  cout << a[1] << a[2] << endl;

  cout << "Enter to letters (no spaces)\n";
  cin >> a[1] >> a[2];
  cout << "You entered: \n";
  cout << a[1] << a[2] << endl;

  return 0;
}
