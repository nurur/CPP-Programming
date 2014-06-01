// Example 6.7, 6.8  
// Side Effect, Unhandled Exception 
// Side effect : when passing objects to function in C++


#include <iostream>
using namespace std;


// The following function has no side-effect. 
int foo(int a, int b) 
{ return (a + b); }

// The following function has side-effect. 
// Modifying the caller's object a is an additional effect 
// of the function beyond simply computing a return value. 
int bar(int &a, int &b) 
{ return (++a + b); }



int main()
{
  // Check
  // Side Effect
  cout << "Highlighting side effects  ... ... : " << endl;

  const int SIZE = 4;
  float a[] = { 22.2, 44.4, 66.6 };
  for (int i=0; i<SIZE; i++)
    cout << a[i] << " ";
  cout << endl;

  float x = 11.1;
  cout << "x = " << x << endl;

  a[3] = 88.8;
  cout << "x = " << x << endl;

  for (int i=0; i<SIZE; i++)
    cout << a[i] << " ";
  cout << endl;
  cout << endl;


  // Check 
  // Side Effect 
  int m=22, n=44;
  cout << "foo(int a, int b)   : " << foo(m,n) << endl;
  cout << "m = " << m << ", n= "<< n << endl;

  cout << "bar(int &a, int &b) : " << bar(m,n) << endl;
  cout << "m = " << m << ", n= "<< n << endl;
  cout << endl;



  // Check
  // Unhandled Exception 
  cout << "Highlighting unhandled exceptions : " << endl;

  float b[] = { 22.2, 44.4, 66.6 };
  for (int i=0; i<SIZE; i++)
    cout << b[i] << " ";
  cout << endl;

  float y = 11.1;
  cout << "y = " << y << endl;

  b[33] = 88.8;                // Error: Index out of bound 
  cout << "y = " << y << endl;

  for (int i=0; i<SIZE; i++)
    cout << b[i] << " ";
  cout << endl;



  return 0;
}


