
#include <cmath>
#include <iostream>
using namespace std;



void print (char* str)
// Expects a non-const char
{ cout << str << endl; }



int main()
{
  double amount      = 101.63;
  double doubleCents = amount * 100;
  int intCents       = (round(fabs(doubleCents)));

  cout << doubleCents << " " << intCents%100 << endl;

  float a = 9.0;
  float b = 2.0;
  cout << a/b << endl;

  int c = 9;
  int d = 2;

  float e = static_cast<float>(c)/d;
  cout << c/d << endl;
  cout << e << endl;

  
  char c1 = 'A';
  char c2 = 'a';
  cout << static_cast<int>(c1) << endl;
  cout << static_cast<int>(c2) << endl;
 
  const char* c3 = "simple text";
  cout << const_cast<char*>(c3) << endl;



  return 0;
}
