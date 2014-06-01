// Example 
// Type-cast


#include <cmath>
#include <iostream>
using namespace std;



void print (char* str)
// Expects a non-const char
{ cout << str << endl; }



int main()
{
  // Floating-point division 
  float a = 9.0;
  float b = 2.0;
  cout << a/b << endl;

  //Integer division  
  int c = 9;
  int d = 2;
  cout << c/d << endl;


  // Type Cast, static_cast<> 
  float e = static_cast<float>(c)/d;
  cout << e << endl;

  char c1 = 'A';
  char c2 = 'a';
  cout << static_cast<int>(c1) << endl;
  cout << static_cast<int>(c2) << endl;
 

  // Type Cast, const_cast<> 
  const char* c3 = "simple text";
  print( const_cast<char*>(c3) );
  cout << endl;


  return 0;
}
