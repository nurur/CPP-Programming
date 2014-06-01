// Problem 5.8, chap 5 (C++, J R Hubbard)
// Function overloading 


#include <iostream>
using namespace std;


int min(int a, int b)
{
  if (a > b) return b;
  else return a;

}


int min(int a, int b, int c, int d)
{
  int mn;
  mn = min(a, b);
  mn = min(mn,c);
  mn = min(mn,d);
  return mn;
}




int main ()
{
  int a, b, c, d;
  a = 12; b = 5; c = 14; d = 21;
  int mn = min(a,b,c,d);
  cout << "The minimum number is: " << mn << endl;

  return 0;
}
