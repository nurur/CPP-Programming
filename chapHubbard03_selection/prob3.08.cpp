// Problems 3.8, chapter 3 (C++, J. R. Hubbard) 
// The switch construct


#include <iostream>
using namespace std;


int main()
{
  int m, n;
  char c, cc;
  cout << "Provide the integers : ";  cin >> m >> n;
  cout << "Provide the character: ";  cin >> c;

  switch(c)
    {
    case '+' : cout << "The sum of the integers is            : " 
		    << m+n; break;
    case '-' : cout << "The difference between the integers is: " 
		    << m-n; break;
    case '*' : cout << "The product of the integers is        : " 
		    << m*n; break;
    case '/' : cout << "The quotient of the integers is       : " 
		    << m/n; break;
    case '%' : cout << "The remainder of the integers is      : " 
		    << m%n; break;
    }  
  
  cout << endl;
  return 0;
}
