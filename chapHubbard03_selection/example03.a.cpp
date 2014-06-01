// EXAMPLE 3A: program using "if ... else" statement 

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


  if (op == '+')  
    cout << "the output is: " << p+q << endl;
  else if  (op == '-')  
      cout << "the output is: " << p-q << endl;
    else if  (op == '*')  
	cout << "the output is: " << p*q << endl;  
      else if (op == '/')  
	  cout << "the output is: " << p/q << endl;

	else cout << "end of the program" << endl; 
  return 0;
}
