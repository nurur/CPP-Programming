// Example:
// Type Conversion 


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



int main()
{
  int m = 1492;
  cout << "Base  8: n = " << oct << m << endl;
  cout << "Base 10: n = " << dec << m << endl;
  cout << "Base 16: n = " << hex << m << endl;
  cout << endl;

  int n = 02724;
  cout << "Base  8: n = " << oct << n << endl;
  cout << "Base 10: n = " << dec << n << endl;
  cout << "Base 16: n = " << hex << n << endl;
  cout << endl;


  int o = 0x5d4;
  cout << "Base  8: n = " << oct << o << endl;
  cout << "Base 10: n = " << dec << o << endl;
  cout << "Base 16: n = " << hex << o << endl;

  return 0;
}
