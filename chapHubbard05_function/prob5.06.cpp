// Problem 5.6, chap 5 (C++, J R Hubbard)
// Max and Min of 4 numbers 


#include <iostream>
using namespace std;


int min(int a, int b, int c, int d)
{
  int mn = a;
  if (b < mn) mn = b;
  if (c < mn) mn = c;
  if (d < mn) mn = d;

  return mn;
}

int max(int a, int b, int c, int d)
{
  int mx = a;
  if (b > mx) mx = b;
  if (c > mx) mx = c;
  if (d > mx) mx = d;

  return mx;
}




int main ()
{
  int a, b, c, d;
  a = 12; b = 5; c = 14; d = 21;
  int mn = min(a,b,c,d);
  cout << "The minimum number is: " << mn << endl;

  int mx = max(a,b,c,d);
  cout << "The maximum number is: " << mx << endl;

  return 0;
}
