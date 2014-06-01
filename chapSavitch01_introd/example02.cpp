// Example 
// Formatting numbers with Decimal Point


#include <cmath>
#include <iostream>
using namespace std;


int main()
{

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(8); 

  double price = 78.5;
  cout << "The prcie is: " << price << endl; 

  return 0;
}
