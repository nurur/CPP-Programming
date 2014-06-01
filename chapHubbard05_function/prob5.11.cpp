// Problem 5.11, chap 5 (C++, J R Hubbard)
// Factorial Function & Integer Overflow
// 
// For integer overflow occurs at i=17
// For long integer overflow occurs at i=21


#include <iostream>
using namespace std;


int factFunc(int n)
{  
  if (n<0) return 0;

  int f = 1;
  for (int i=1; i<=n; i++)
    f *= i; 
  return f;  
}



int main()
{
  for (int i=0; i<25; i++)
    cout << i << " " << factFunc(i) << endl;
  
  return 0;
}
