// use 'while' statement to execute the loop  

#include <iostream>
#include <math.h>
using namespace std;


int main()
{
  int n;         // numberv to test
  int i;         // loop counter
  int is_prime;  // Boolean flag
  
  is_prime = true;

  //get a number from keyboarf.

  cout << "Enter a number and press Enter: ";
  cin >> n;
  cout << " ";

  //test for primness

  i=2;
  while (i <= sqrt(static_cast<double>(n))){

    if (n % i == 0) 
      is_prime = false;
    i++;
  }


  // print results

  if (is_prime)
    cout << "Number is prime." << "\n";
  else
    cout << "Number is not prime." << "\n";

  return 0;
}
