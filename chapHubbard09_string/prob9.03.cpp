// Problem 9.3

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


int main()
{
  string s;
  int n;
  float x;
  cin >> s >> n >> x >> s; 
  // ABC 456  7.89  XYZ
  // ABC 4567  .89  XYZ
  // ABC 4567 7.8  9XYZ
  

  cout << s << " " << n << " " << x << " " <<  s << endl; 
  return 0;
}
