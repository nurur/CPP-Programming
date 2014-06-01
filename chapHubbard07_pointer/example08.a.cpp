// Example: 7.18
// Pointer to Function 
// Calling a Function from another Function 


#include <iostream>
using namespace std;



int cube(int n)
{ return n*n*n; }

int square(int n)
{ return n*n; }


int sum(int m, int (*funcToCall)(int n) )
{
  int i, s;

  s=0;
  for(i=1; i<=m; i++)
    s += (*funcToCall)(i);

  return s;
}



int main()
{
  int m, n;
  m = sum(4,cube);
  cout << "Calling cube function  : " << m << endl;
  n =  sum(4,square);
  cout << "Calling square function: " << n << endl;


  return 0;
}
