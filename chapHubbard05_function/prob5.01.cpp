// Problem 5.1, chap 5 (C++, J R Hubbard)
// Boolean function  Revisited


#include <iostream>
using namespace std;


bool isLeapYear(int);


int main ()
{
  int n;
  cout << "testing Leap year function: " << endl; 

  do 
    {cout << "enter a year              : "; 
      cin >> n;
      if (isLeapYear(n)) cout << n << " is a Leap year" << endl;
      else cout << n << " is not a Leap year!" << endl;
    } while (n > 1);
  
  return 0;
}


bool isLeapYear(int n)
// returns true iff n is a Leap year
{ 
  int a;
  a = n % 4 == 0 && (n % 100 != 0 || n % 400 == 0);
  return a;
}
