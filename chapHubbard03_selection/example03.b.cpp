// EXAMPLE 3B: program using "switch" statement 

#include <iostream>
using namespace std;


int main ()
{
  int p, q;
  char op;
  cout << "enter the integers: " << endl;
  cin  >> p >> q;

  cout << "enter the operator: " << endl;
  cin  >> op;

  switch (op)
    {case '+': cout << "the output is: " << p+q << endl; break;
    case '-':  cout << "the output is: " << p-q << endl; break;
    case '*':  cout << "the output is: " << p*q << endl; break;  
    case '/':  cout << "the output is: " << p/q << endl; break;
    case '%':  cout << "the output is: " << p%q << endl; break;
    }

  return 0;
}
