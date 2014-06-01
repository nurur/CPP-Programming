// Example 15.1, 15.2 
// Inheritance 
// Base Class with Virtual Member Function 



#ifndef SALE_HPP
#define SALE_HPP


#include <cstdlib>
#include <iostream>
using namespace std;



// Class Interface
class Sale
{
  friend bool operator<(const Sale& first, const Sale& second);

public:
  Sale();
  Sale(double thePrice);

  double getPrice() const;
  void setPrice(double newPrice);

  virtual double bill() const;

  double savings(const Sale& other) const;

  private:
  double price;
};



// Class Implementation 
bool operator<(const Sale& first, const Sale& second)
{
  return ( first.bill() < second.bill() );
}

Sale :: Sale(): price(0) { } 

Sale :: Sale(double thePrice) 
{ 
  if (thePrice >= 0) 
    price = thePrice;
  else
    {
      cout << "Error: Cannot have a negative price\n";
      exit(1);
    } 
} 

double Sale :: getPrice() const 
{ return price; } 

void Sale :: setPrice(double newPrice) 
{ 
  if (newPrice >= 0) 
    price = newPrice;
  else
    {
      cout << "Error: Cannot have a negative price\n";
      exit(1);
    }
}

double Sale :: bill() const { return price; }

double Sale :: savings(const Sale& other) const
{
  return ( bill() - other.bill() );
}



#endif   //SALE_HPP
