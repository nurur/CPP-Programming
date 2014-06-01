// EXAMPLE: 5.17 
// Pass by value and Pass by reference 
// Return by value and Return by reference 


#include <iostream>
using namespace std;


//Pass by value and Return by value
int f(int x)  
{
  //return (x *= 2); 
  int newX = x * 2;  
  return newX;
}


//Pass by reference and Return by reference 
//case 1: int g(int& x) produces garbage if x is Modified and Returned  
int g1(int& x) 
{ x *= 2; }

//case 2: int g(int& x) is okay if x is Assigned to newX and Returned newX
int g2(int& x) 
{  
  int newX = x * 2; 
  return newX;
}

//case 3: int& g(int x) produces segmentation fault if 
// x is Modified and Returned 
int& g3(int x) 
{ x *= 2; }

//case 4: int& g(int x) is okay if x is Assigned to newX and Returned newX
//However it gives warning about reference to local variable ‘newX’ returned
int& g4(int x) 
{ 
  int newX = x * 2; 
  return newX;
}

// case 5: correct way 
int& g5(int& x) 
{ x *= 2; }

//Pass by reference and Return none 
void g6(int& x) 
{ x *= 2; }


void func(int x, int& y)
{
  x=88; y=99;
  cout << "inside: x = " << x << ", y = " << y << endl;
}


void func(int x, int& y, const int& z)
{
  x = x+z;
  y = y+z;
  cout << "inside: x = " << x << ", y = " << y << ", z = " << z << endl;
}



int main()
{
  int a=22, b=33;
  cout << "before: a = " << a << ", b = " << b << endl;
  func(a,b);
  cout << "after : a = " << a << ", b = " << b << endl;
  cout << endl;

  int a2=22, b2=33, c2=44; 
  cout << "before: a = " << a2 << ", b = " << b2 << ", c = " << c2 << endl;
  func(a2,b2,c2);
  cout << "after : a = " << a2 << ", b = " << b2 << ", c = " << c2 << endl;
  cout << endl;


  // converting a reference parameter into a return value
  int m = 3, n = 3, q = 3, r = 3, s = 3, t = 3, u=3;


  cout << "Pass by value and Return by value : " << endl;
  cout << "int   f(int m) : " << f(m) << endl;
  cout << endl;

  cout << "Pass by reference and Return by reference : " << endl;
  cout << "int  f(int& m) : " << g1(n) << endl;
  cout << "int  f(int& m) : " << g2(q) << endl;
  //cout << "int&  f(int m) : " << g3(r) << endl;
  cout << "int&  f(int m) : " << g4(s) << endl;

  cout << "int&  f(int m) : " << g5(t) << endl;
  cout << endl;

  g6(u); 
  cout << "void f(int& m) : " << u << endl;

  return 0;
}

