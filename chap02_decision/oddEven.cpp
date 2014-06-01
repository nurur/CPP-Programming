#include <iostream>
using namespace std;


int main() 
{ 
  int n;

  cout << "Enter a number and press Enter: ";
  cin >> n;
  
  if (n%2 == 0)
    cout << "This number is even." << "\n" ;
  else
    cout << "This number is odd."  << "\n" ;

  return 0;
}
