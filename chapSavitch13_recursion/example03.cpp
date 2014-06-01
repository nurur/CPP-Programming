// Example: Recursive Function
// Recusive Function that Returns a Value: 
// Note:
// void exit (int status) 
// 0 = success, 1 = failure



#include <cstdlib>
#include <iostream>
using namespace std;



// Auxiliary function 
int power(int x, int n)
{
  if (x < 0)
    { 
      cout << "Illegal argument to power\n";
      exit(1); 
    }

  if (n == 0) return 1;
  return ( power(x, n-1) * x);
}


// Recursive function 
// Each call gets its own count
int factFunc( int n ) 
{
  if (n <= 0)
    { 
      cout << "Illegal argument for factorial\n";
      exit(1);
    }
  
  if (n == 1) return 1; 
  return (n * factFunc( n-1 ));
}


int main()
{
  // Power function 
  cout << "Recursive Func. with Return Value: Power Function     " << endl;

  for (int i = 0; i < 4; i++) 
    cout << "3 to the power " << i << " is " 
	 << power(3,i) << endl;
  cout << endl;
  

  // Factorial function
  cout << "Recursive Func. with Return Value: Factorial Function " << endl;
  cout << factFunc(4);   
  cout << endl;


  cout << endl;
  return 0;
}
