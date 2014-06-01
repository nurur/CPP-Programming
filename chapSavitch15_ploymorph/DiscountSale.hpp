// Example 15.3, 15.4 
// Inheritance 
// Derived Class with Virtual Member Function 



#ifndef DISCOUNTSALE_HPP
#define DISCOUNTSALE_HPP
#include "Sale.hpp"



// Class Interface
class DiscountSale : public Sale 
{
public:
  DiscountSale();
  DiscountSale(double thePrice, double theDiscount);
  
  double getDiscount() const;
  void setDiscount(double newDiscount);

  virtual double bill() const;

private:
  double discount;
};


DiscountSale :: DiscountSale() 
  : Sale(), discount(0) { }

DiscountSale :: DiscountSale(double thePrice, double theDiscount) 
  : Sale(thePrice), discount(theDiscount) { }

double DiscountSale :: getDiscount() const
{ return discount; }

void DiscountSale :: setDiscount(double newDiscount)
{ discount = newDiscount; }

double DiscountSale ::  bill() const
{
  double fraction = discount/100;
  double tmp      = (1-fraction) * getPrice();
  return tmp;
}


#endif   //DISCOUNTSALE_HPP
