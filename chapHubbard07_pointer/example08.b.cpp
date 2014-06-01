// Example: 7.18
// Pointer to Function 
// Calling of a Function from another Function 


#include <iostream>
using namespace std;

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*funcToCall)(int,int))
{
  int g;
  g = (*funcToCall)(x,y);

  return g;
}


int main ()
{
  int m, n;
  m = operation (7, 5, addition);
  cout << "Addition of two numbers    : " << m << endl;
  n = operation (20, m, subtraction);
  cout << "Subtraction of two numbers : " << n << endl;


  //Alternative way of assigning function name  
  int (*minus)(int,int) = subtraction;
  //Minus is a pointer to a function that has two parameters of type int. 
  //It is immediately assigned to point to the function subtraction, 
  n = operation (20, m, minus);
  cout << n << endl;


  return 0;
}
