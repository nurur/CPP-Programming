// EXAMPLE 5.14 
// Boolean function  


#include <iostream>
using namespace std;


bool isLeapYear(int n)
// Returns true iff n is a Leap year
{ 
  int a;
  a = n % 4 == 0 && n % 100 != 0 || n % 400 == 0;
  return a;
}



int main ()
{
  int n;
  cout << "testing Leap year function: " << endl; 

  do 
    {
      cout << "enter a year              : "; 
      cin >> n;
      if (isLeapYear(n)) cout << n << " is a Leap year" << endl;
      else cout << n << " is not a Leap year!" << endl;
    } while (n > 1);
  
  return 0;
}



