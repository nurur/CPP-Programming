#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;


int main()
{
  char c = '2';
  cout << c << endl;
  cout << ( static_cast<int>(c) - static_cast<int>('0') ) << endl;
  cout << static_cast<int>('0') << endl;


  double d = 3.14155926;
  int i    = static_cast<int> (d);
  cout << i << endl;


  int j = 41;
  int v = 3;
  float m = j/v;
  float n = static_cast<float> (j)/v;
  cout << m << " " << n << endl;

  return 0;
}
