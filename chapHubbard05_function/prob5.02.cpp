// Problem 5.1, chap 5 (C++, J R Hubbard)
// Void function and Return function  


#include <iostream>
using namespace std;


void voidFunc(int& x)
{
  int tmp = 2*x;
  x = tmp;
}

int returnFunc(int x)
{
  int tmp = 2*x;
  return tmp;
}


int main ()
{
  int m = 5; 
  int n; 
  n = m;
  
  voidFunc(m);
  cout << "Output from voidFunc()  : " << m << endl;
  
  int t = returnFunc(n);
  cout << "Output from returnFunc(): " << t << endl;


  return 0;
}
