// Example 15.5


#include "Sale.hpp"
#include "DiscountSale.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;



int main()
{
  Sale regularSale(10.00);
  DiscountSale discountSale(15.00, 25);


  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  if (discountSale < regularSale)
    {
      cout << "Discount item is cheaper.\n";
      cout << "Savings is $" 
	   << regularSale.savings(discountSale)
	   << endl;
    }
  else
    {
      cout << "Discounted item is not cheaper.\n";
    }

  return 0;
}
