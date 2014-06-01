// Problem 5.7, chap 5 (C++, J R Hubbard)
// Function overloading 


#include <iostream>
using namespace std;


int max(int a, int b)
{
  if (a < b) return b;
  else return a;

}


int max(int a, int b, int c, int d)
{
  int mx;
  mx = max(a, b);
  mx = max(mx,c);
  mx = max(mx,d);
  return mx;
}




int main ()
{
  int a, b, c, d;
  a = 12; b = 5; c = 14; d = 21;
  int mx = max(a,b,c,d);
  cout << "The maximum number is: " << mx << endl;

  return 0;
}
